#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <mysql/mysql.h>

// ===================== 配置区 =====================
#define RING_BUF_CAPACITY 100 // 环形缓冲区容量，存100条就批量入库
#define COLLECT_INTERVAL 1    // 采集间隔 秒
#define DB_HOST "127.0.0.1"
#define DB_USER "tom"
#define DB_PASS "123456"
#define DB_NAME "monitor"
// ==================================================

// 单条CPU采集数据结构
typedef struct
{
    time_t timestamp;
    float usage;
    float load1, load5, load15;
    int core_cnt;
} CpuData;

// 环形缓冲区结构体
typedef struct
{
    CpuData *buf;
    int capacity;
    int write_idx; // 下一个写入位置
    int count;     // 当前有效数据条数
} RingBuffer;

// 环形缓冲区初始化
static int ring_buf_init(RingBuffer *rb, int cap)
{
    rb->buf = (CpuData *)malloc(sizeof(CpuData) * cap);
    if (!rb->buf)
        return -1;
    rb->capacity = cap;
    rb->write_idx = 0;
    rb->count = 0;
    return 0;
}

// 写入环形缓冲区，返回1代表缓冲区已满需要落库
static int ring_buf_push(RingBuffer *rb, const CpuData *data)
{
    rb->buf[rb->write_idx] = *data;
    rb->write_idx = (rb->write_idx + 1) % rb->capacity;

    if (rb->count < rb->capacity)
    {
        rb->count++;
        return 0; // 未填满
    }
    return 1; // 已满，触发入库
}

// 释放环形缓冲区
static void ring_buf_free(RingBuffer *rb)
{
    if (rb->buf)
        free(rb->buf);
    rb->buf = NULL;
}

// 计算CPU使用率 读取/proc/stat
static float get_cpu_usage()
{
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp)
        return -1.0f;

    unsigned long long user1, nice1, sys1, idle1, iowait1, irq1, softirq1;
    fscanf(fp, "cpu %llu %llu %llu %llu %llu %llu %llu",
           &user1, &nice1, &sys1, &idle1, &iowait1, &irq1, &softirq1);
    fclose(fp);

    unsigned long long total1 = user1 + nice1 + sys1 + idle1 + iowait1 + irq1 + softirq1;
    unsigned long long work1 = user1 + nice1 + sys1;

    sleep(COLLECT_INTERVAL);

    fp = fopen("/proc/stat", "r");
    fscanf(fp, "cpu %llu %llu %llu %llu %llu %llu %llu",
           &user1, &nice1, &sys1, &idle1, &iowait1, &irq1, &softirq1);
    fclose(fp);

    unsigned long long total2 = user1 + nice1 + sys1 + idle1 + iowait1 + irq1 + softirq1;
    unsigned long long work2 = user1 + nice1 + sys1;

    unsigned long long total_delta = total2 - total1;
    unsigned long long work_delta = work2 - work1;

    if (total_delta == 0)
        return 0.0f;
    return (float)work_delta / total_delta * 100.0f;
}

// 获取系统负载与CPU核心数
static void get_load_and_core(float *l1, float *l5, float *l15, int *core)
{
    // 负载
    double avg[3];
    getloadavg(avg, 3);
    *l1 = (float)avg[0];
    *l5 = (float)avg[1];
    *l15 = (float)avg[2];

    // 核心数
    FILE *fp = fopen("/proc/cpuinfo", "r");
    char line[256];
    int cnt = 0;
    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, "processor\t:"))
            cnt++;
    }
    fclose(fp);
    *core = cnt;
}

// 缓冲区满后批量插入MySQL
static int batch_insert_mysql(RingBuffer *rb)
{
    MYSQL mysql;
    MYSQL_RES *res;

    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0))
    {
        fprintf(stderr, "MySQL connect fail: %s\n", mysql_error(&mysql));
        return -1;
    }

    // 构造批量INSERT语句
    char sql_buf[8192] = "INSERT INTO cpu(collect_time,cpu_usage,core_num,load_avg1,load_avg5,load_avg15) VALUES ";
    char val_buf[256];

    for (int i = 0; i < rb->capacity; i++)
    {
        CpuData *d = &rb->buf[i];
        struct tm *tm = localtime(&d->timestamp);
        char time_str[32];
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm);

        snprintf(val_buf, sizeof(val_buf),
                 "('%s',%.2f,%d,%.2f,%.2f,%.2f),",
                 time_str, d->usage, d->core_cnt,
                 d->load1, d->load5, d->load15);
        strcat(sql_buf, val_buf);
    }

    // 删掉最后多余的逗号
    int len = strlen(sql_buf);
    sql_buf[len - 1] = ';';

    // 执行SQL
    if (mysql_query(&mysql, sql_buf))
    {
        fprintf(stderr, "Insert fail: %s\nSQL:%s\n", mysql_error(&mysql), sql_buf);
        mysql_close(&mysql);
        return -1;
    }

    printf("===== 缓冲区已满，批量入库 %d 条数据 =====\n", rb->capacity);

    // 清空缓冲区计数，复用环形空间
    rb->count = 0;
    rb->write_idx = 0;

    mysql_close(&mysql);
    return 0;
}

int main(void)
{
    RingBuffer rb;
    if (ring_buf_init(&rb, RING_BUF_CAPACITY) != 0)
    {
        perror("ring buffer malloc failed");
        return 1;
    }

    printf("CPU monitor running, ring buffer capacity: %d\n", RING_BUF_CAPACITY);

    while (1)
    {
        CpuData data;
        data.timestamp = time(NULL);
        data.usage = get_cpu_usage();
        get_load_and_core(&data.load1, &data.load5, &data.load15, &data.core_cnt);

        printf("[%s] CPU:%.2f%% Load:%.2f/%.2f/%.2f Core:%d\n",
               ctime(&data.timestamp), data.usage,
               data.load1, data.load5, data.load15, data.core_cnt);

        // 写入环形缓冲区，满了自动入库
        int full = ring_buf_push(&rb, &data);
        if (full)
        {
            batch_insert_mysql(&rb);
        }
    }

    ring_buf_free(&rb);
    return 0;
}