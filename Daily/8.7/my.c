// my.c

// my.c
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

#define HOST "127.0.0.1"
#define USER "tom"
#define PASSWORD "123456"
#define DB "hr"
#define POST 3306

int main(void)
{
    MYSQL *conn;

    // 1. 初始化MYSQL句柄
    conn = mysql_init(NULL);
    if (conn == NULL)
    {
        fprintf(stderr, "mysql_init 失败\n");
        return EXIT_FAILURE;
    }

    // 2. 建立数据库连接
    if (mysql_real_connect(conn,
                           "127.0.0.1", // 主机
                           "tom",       // 用户名
                           "123456",    // 密码
                           "hr",        // 数据库名hr
                           3306,        // 端口
                           NULL,        // socket填NULL
                           0) == NULL)  // clientflag=0
    {
        fprintf(stderr, "数据库连接失败：%s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }
    char *sql = "select id,name,city from dept where name = ";
    // char *sql = "insert into dept values(NULL,'Test','Changsha')";
    char *dept = "abc";
    char *city = "xyz";
    // char sql[128] = {0};
    // sprintf(sql,"insert into dept values(NULL,'%s','%s')",dept,city);

    if (mysql_query(conn, sql))
    {
        fprintf(stderr, "执行查询错误:%s\n", mysql_error(conn));
        return EXIT_FAILURE;
    }

    MYSQL_RES *res = mysql_store_result(conn); // 结果集
    int cols = mysql_num_fields(res);          // ✅正确

    MYSQL_FIELD *fields = mysql_fetch_fields(res);

    // 打印表头（列名）
    for (int i = 0; i < cols; i++)
    {
        printf("%s\t", fields[i].name);
    }
    printf("\n");

    
    // MYSQL_ROW row;          //行
    // int cols1 = res->field_count;    //列
    // while ((row = mysql_fetch_row(res))!=NULL)
    // {
    //     for (int i = 0; i < cols1; i++)
    //     {
    //         printf("%s\t",row[i]);
    //     }
    //     printf("\n");
    // }
    mysql_free_result(res);

    printf("✅数据库连接成功！\n");

    // 设置字符集（可选，防止后续中文乱码）
    mysql_set_character_set(conn, "utf8mb4");
    // 用完关闭连接，必须写
    mysql_close(conn);
    return 0;
}