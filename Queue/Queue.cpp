#include <iostream>
#include "Queue.h"
#include <stdio.h>
#include <malloc.h>
using namespace std;
/*1.静态数组实现*/
//#define QUEUE_SIZE 5 //定义队列的大小
//#define ARRARY_SIZE 5
//static QUEUE_TYPE Queue[ARRARY_SIZE]; //声明一个存储队列元素的数组
//static int font = 1; //指向队首
//static int rear = 0;//指向队尾

/*2.动态数组实现*/
static unsigned int queue_size;//初始为0，需要外部输入
static QUEUE_TYPE *Queue; //声明存储指向队列指针和指向队首和队尾元素的下标
static int font = 1;
static int rear = 0;

void Insert(QUEUE_TYPE value)
{
    if (!Is_full())
    {
//        rear = (rear + 1) % ARRARY_SIZE; //循环数组下表的变化不是简单的++，--
        rear = (rear + 1) % queue_size;//动态数组中queueu_sizae是外界输入的
        Queue[rear] = value;
    }
    else
    {
        cout << "the queue is full" << endl;
    }
}

void Delete(void)
{
    if (!Is_empty())
    {
//        font = (font + 1)%ARRARY_SIZE;
        font = (font + 1)%queue_size;
    }
    else
    {
        cout << "the queue is empty,the delete isn't admited" << endl;
    }
}

QUEUE_TYPE First(void)
{
    if (!Is_empty())
    {
        return Queue[font];
    }
    return -65535;

}

bool Is_empty(void)
{
//    return (rear+1)%ARRARY_SIZE == font;
    return (rear+1)%queue_size == font;
}

bool Is_full()
{
    //return (rear+2)%ARRARY_SIZE == font;
    return (rear+2)%queue_size == font;
}

//从顶部开始打印队列元素
void PrintQueue(){

    for (int i = font; i <= rear; i++) {
        printf("%d ",Queue[i]);
    }
    printf("\n");
}

void CreateQueue(unsigned int size){
    if (queue_size == 0) {
        queue_size = size;
        Queue = (int*)malloc(queue_size * sizeof(QUEUE_TYPE));
        if (Queue == NULL) {
            cout << "数组内存分配失败" << endl;
        }
    }
}

void DestroyQueue(){
    if (queue_size > 0) {
        queue_size = 0;
        free(Queue);
        Queue = NULL;//数组置空
        font = 1;
        rear = 0;
    }
}

/*链式队列，是完全不同于数组方式实现*/
typedef struct QUEUE_NODE
{
    QUEUE_TYPE value;
    struct QUEUE_NODE *link;
}QueueNode;

static QueueNode *fontp,*rearp;//定义一个固定的指向队首和队尾的指针

void LInitial() //初始化队列
{
    rearp=fontp=(QueueNode *)malloc(sizeof(QueueNode));
    fontp->link = 0;

}

void LInsert(QUEUE_TYPE value)//在队尾插入元素操作，主要是对队尾进行操作，把此时队尾的作用和堆栈的栈顶指针相同都是指向新节点。但是此时我们尝试队尾节点不指向上一个节点而是指向空(尾插法)
{
    QueueNode *new_node;
    new_node = (QueueNode*)malloc(sizeof(QueueNode));

    if (new_node != 0)//如果节点分配内存成功,就把他插入在队尾
    {
        new_node -> link = 0;
        new_node -> value = value;

        rearp -> link = new_node;
        rearp = new_node;

    }
}
void LDelete(void)//删除队首元素操作，使得队首指针向后移动一位
{
    if (!LIs_empty())
    {
       fontp = fontp->link ;
    }
}

QUEUE_TYPE LQueueFont()
{
    if (!LIs_empty())
    {
        return fontp -> link -> value;//fontp->link才是队首元素，rearp就是队尾元素
    }
}

bool LIs_empty(void)//队首指针和队尾指针同时指向空，说明链表为空，同时说明队列为空
{
    return fontp->link == 0 & rearp->link == 0;

}
void LDestoryQueue(void)
{
    while (!LIs_empty())
    {
        LDelete();
    }
}
void LPrintQueue()//从队首到队尾
{
    QueueNode *r,*f;
    f = fontp->link;//f指向队首
    r = rearp->link;//指向队尾的下一元素

    while (r != f)
    {
        cout << f->value <<endl;
        f = f->link;

    }
}



