#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int a = 0 ;
void exit_s(int status)
{
    if(WIFEXITED(status))
        printf("child process normal exit\n");
    else if(WIFSIGNALED(status))
        printf("child process killed by signal\n");
}
int main (int argc, char ** argv) {
    pid_t pId = fork();
    int status;//定义一个变量来接受子进程退出的状态
    if (pId == -1) {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    else if (pId == 0) { // fork创建成功,在子进程中返回0,这里是子进程的操作
        int myPid = getpid();
        int parentPid = getppid();

        printf("ChildID=%d ParentID=%d \n", myPid, parentPid);
        //int i = 0;
        for (int i=0;i<5;i++)
        {
            printf("child process:%d\n",a++);
            sleep(1);
        }
        printf("chilid process is over\n");
        exit(0);//子进程执行完毕后,退出
    }

    else { // 这里是主进程的操作
        wait(&status);//主进程等待子进程,阻塞主进程
        exit_s(status);
        printf("child process is finished,parent process continued\n");
        printf("ParentID=%d ChildPID=%d \n", getpid(), pId);
        //int i = 0;
         for (int i=0;i<5;i++)
        {
            printf("main process:%d\n",a++);
            sleep(1);
        }

    }

//      else if (pId == 0){
//		//child process
//		execl("/bin/echo","echo","child process is running" ,NULL);
//		sleep(1);
//		printf("child process is over\n");
//		exit(0);
//		}
//      else{
//		//parent process
//		wait(NULL);
//		printf("execv done\n\n");
//	}
    printf ("main process is over\n");//加不加'\n'结果是有差距的
    exit(0);
    //sleep(5);

    return EXIT_SUCCESS;
}


