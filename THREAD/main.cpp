/*----使用stl thread--------*/
//#include <iostream>       // std::cout  std::cin
//#include <unistd.h>
//#include <thread>         // std::thread
//using namespace std;
//int a = 1;
//void foo()
//{
//    // do stuff...
//
//    while (1)
//    {
//        cout << "first thread" << endl;
//        cout << "a:"<<a<<endl;
//        sleep(5);
//    }
//
//}
//void bar(int x)
//{
//    // do stuff...
//    cout << "second thread" <<endl;
//}
//int main()
//{
//    std::cout << "main, foo and bar now execute concurrently...\n\n";
//    //std::thread first(foo);     // spawn new thread that calls foo()
//    std::thread second(bar, 100);  // spawn new thread that calls bar(0)
//
//    // synchronize threads:
//    //first.detach();
//    while (1)
//    {
//        cout << "main thread" << endl;
//        cout << "a:"<<a<<endl;
//        a++;
//        sleep(1);
//    }          // pauses until first finishes
//    second.join();               // pauses until second finishes
//    std::cout << "foo and bar completed.\n\n";
//    return 0;
//}


/*-----使用boost thread*---*/
//#include </usr/include/boost/thread/thread.hpp>
//#include <iostream>
//#include <unistd.h>
//using namespace std;
//void hello()
//{
//        std::cout <<
//        "Hello world, I''m a thread!"
//        << std::endl;
//}
//
//int main(int argc, char* argv[])
//{
//        boost::thread thrd(&hello);
//        thrd.join();
//        return 0;
//}




/*---------c语言多线程编程 -- pthread----*/
//#include<pthread.h>
//#include<stdio.h>
//#include<stdlib.h>
//#include<unistd.h>
//int value = 0;
//pthread_mutex_t mutex;//定义一个互斥量，即定义一把全局数据锁
//pthread_cond_t cond;//定义一个条件量
//void *newthread(void *arg)//这里还必须设置参数？即使不传参
//{
//    pthread_mutex_lock(&mutex);
//    //printf("new thread get the mutex\n");
//    while(value < 10)//设置休眠条件
//    {
//        printf("new thread is sleep,waitting for waking up\n");
//        pthread_cond_wait(&cond,&mutex);//休眠函数
//    }
//    printf("new thread waked up\n");
//    while(value > 0)
//    {
//        printf("new thread:%d\n",value--);
//        sleep(1);
//
//    }
//    pthread_mutex_unlock(&mutex);
//    //printf("new thread release the mutex\n");
//    pthread_exit((void *)"new thread exit\n");//子线程调用exit终止自己
//
//}
//int main()
//{
//    pthread_t thread_id;//定义线程标识符
//    void *thread_return;
//    pthread_attr_t thread_attr;
//    sched_param param;//存放线程优先级的结构体对象
//    int res;
////    pthread_attr_init(&thread_attr);//线程属性初始化
////    pthread_attr_setdetachstate(&thread_attr,PTHREAD_CREATE_DETACHED);//线程设置分离状态
//    pthread_mutex_init(&mutex,NULL);//互斥量初始化
//    pthread_cond_init(&cond,NULL);//条件量初始化
//    res = pthread_create(&thread_id,NULL,newthread,NULL);//创建线程
//    if (res != 0)
//    {
//        printf("创建线程失败\n");
//        exit(0);
//    }
//    sleep(1);
//    while (value < 10)
//    {
//        pthread_mutex_lock(&mutex);//主线程枷锁，对全局变量改变
//        //printf("main thread get the mutex\n");
//        printf("main thread:%d\n",value++);
//        sleep(1);
//        pthread_mutex_unlock(&mutex);//主线程释放锁
//        //printf("main thread release the mutex\n");
//    }
//    if(value >= 10)//设置条件变量激活条件
//    {
//        pthread_cond_signal(&cond);
//    }
//    pthread_join(thread_id,&thread_return);//等待子线程退出
//    printf("%s",(char *)thread_return);//打印子线程退出的返回信息
//    for (int i=1;i<4;i++)
//    {
//        printf("main thread:%d\n",value++);
//        sleep(1);
//    }
//    pthread_mutex_destroy(&mutex);//不用锁的时候，销毁它
//    //printf("the mutex is destroied\n");
//    printf("main thread over\n");
//    return 0;
//}
/* --c语言多线程同步机制之信号量*--*/

#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//线程函数
void *thread_func(void *msg);
sem_t sem;//信号量

#define MSG_SIZE 512

int main()
{
	int res = -1;
	pthread_t thread;
	void *thread_result = NULL;
	char msg[MSG_SIZE];
	//初始化信号量，其初值为0
	res = sem_init(&sem, 0, 0);
	if(res == -1)
	{
		perror("semaphore intitialization failed\n");
		exit(EXIT_FAILURE);
	}
	//创建线程，并把msg作为线程函数的参数
	res = pthread_create(&thread, NULL, thread_func, msg);
	if(res != 0)
	{
		perror("pthread_create failed\n");
		exit(EXIT_FAILURE);
	}
	//输入信息，以输入end结束，由于fgets会把回车（\n）也读入，所以判断时就变成了“end\n”
	printf("Input some text. Enter 'end'to finish...\n");
	while(strcmp("end\n", msg) != 0)
	{
		fgets(msg, MSG_SIZE, stdin);
		//把信号量加1
		sem_post(&sem);
	}

	printf("Waiting for thread to finish...\n");
	//等待子线程结束
	res = pthread_join(thread, &thread_result);
	if(res != 0)
	{
		perror("pthread_join failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined\n");
	//清理信号量
	sem_destroy(&sem);
	exit(EXIT_SUCCESS);
}

void* thread_func(void *msg)
{
	//把信号量减1
	sem_wait(&sem);
	char *ptr;
	ptr = (char *)msg;
	while(strcmp("end\n", (char *)msg) != 0)
	{
		int i = 0;
		//把小写字母变成大写
		for(; ptr[i] != '\0'; ++i)
		{
			if(ptr[i] >= 'a' && ptr[i] <= 'z')
			{
				ptr[i] -= 'a' - 'A';
			}
		}
		printf("You input %d characters\n", i-1);
		printf("To Uppercase: %s\n", ptr);
		//把信号量减1
		sem_wait(&sem);
	}
	//退出线程
	pthread_exit(NULL);
}

