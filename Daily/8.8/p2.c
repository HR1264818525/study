//p2.c
//多进程

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

#define N 8

int main(int argc, char const *argv[])
{
    for (int  i = 0; i < N; i++)
    {
        int pid = fork();
        if (pid == 0)        //pid = 0为子进程
        {
            printf("%d,%d\n",getpid(),getppid());
            sleep(20);
            exit(0);
        }
        
    }
    
    for (int  i = 0; i < N; i++)
    {
        wait(NULL);
    }
    
    printf("master:end\n");
    
    return 0;
}
