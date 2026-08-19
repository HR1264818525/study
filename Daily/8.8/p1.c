// p1.c
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

pid_t fork(void);

int main(int argc, char const *argv[])
{
    
    int pid = fork();
    if (pid== -1)
    {
        perror("创建失败\n");
        return 1;
    }
    if (pid == 0)
    {       //子进程
        printf("worker:%d\t%d\n",getpid(),getppid());       //pid是自己的名字 ppid是夫亲的名字
        // sleep(5);
        
        //1.路径
        //2.程序名
        // 3.参数
        // 4.NULL标识参数结束

        execlp("ls","ls","-l","p2.c",NULL);
        //返回状态码
        exit(1);    //执行结束，子进程死亡
    }
    else
    {       //父进程
        printf("master%d\t%d\n",getpid(),getppid());
        
        // wait(NULL);
        int status;
        waitpid(pid,&status,WUNTRACED);
        if (WIFEXITED(status))
        {
            int val = WEXITSTATUS(status);
            printf("val = %d\n",val);
        }
        
        sleep(30);
        printf("pid:%d\n",pid);
    }
    
    return 0;
}
