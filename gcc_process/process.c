#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
void exit_s(int status)//判断子进程退出状态
{
    if(WIFEXITED(status))
        printf("child process normal exit\n");
    else if(WIFSIGNALED(status))
        printf("child process killed by signal\n");
}
int main (int argc, char ** argv) {
    pid_t pId = fork();
    int fd[2];
    char buffer[100];//定义一个缓冲区,用来读取文件的数据
    int status;
    //创建管道
    if(pipe(fd) == -1)
        printf("pipe create error\n");
    if (pId == -1) {
        perror("fork error");
        exit(EXIT_FAILURE);
    } else if (pId == 0) { // fork创建成功,在子进程中返回0,这里是子进程的操作
        int myPid = getpid();
        int parentPid = getppid();
        //close(fd[0]);//子进程关闭管道的读端
        printf("ChildID=%d ParentID=%d \n", myPid, parentPid);
        int i;
        for (i=0;i<5;i++)
        {
            printf("child process is running\n");
            sleep(1);
        }
        write(fd[1],"pipe test",9);
        printf("chilid process is over\n");
        exit(0);//子进程执行完毕后,退出

    } else { // 这里是主进程的操作
    	close(fd[1]);//主进程关闭管道的写端
        wait(&status);//主进程等待子进程,阻塞主进程
        exit_s(status);//判断子进程退出状态,调用自定义函数
        printf("parent process continued\n");
        printf("ParentID=%d ChildPID=%d \n", getpid(), pId);
        int len = read(fd[0],buffer,4);
        printf("parent process read from child process:%s\n",buffer);
        int i;
        for (i=0;i<5;i++)
        {
            printf("main process is running\n");
            sleep(1);
        }
        
        

    }

    printf ("main process is over\n");//加不加'\n'结果是有差距的
    exit(0);
    //sleep(5);

    return EXIT_SUCCESS;
}


