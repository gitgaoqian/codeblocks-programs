
/*此处介绍堆栈的几种实现的方式*/
#include <memory>
#include <iostream>
#include "stack.h"
#include <stdio.h>
#include <malloc.h>
using namespace std;
/*1.静态数组实现*/
//#define STACK_SIZE 10 //定义栈的大小
//static STACK_TYPE stack[STACK_SIZE]; //声明一个存储堆栈元素的数组
//static int top_index = -1; //指向栈顶的下标

/*2.动态数组实现*/
static unsigned int stack_size;//初始为0，需要外部输入
static STACK_TYPE *stack; //声明存储堆栈的指针和指向栈顶元素的下标
static int top_index = -1;

void Push(STACK_TYPE value)
{
    if (!Is_full())
    {
        stack[++top_index] = value;
    }

}

void Pop(void)
{
    if (!Is_empty())
    {
        top_index--;
    }

}

STACK_TYPE Top(void)
{
    if (!Is_empty())
    {
        return stack[top_index];
    }
    return -1;

}

bool Is_empty(void)
{
    return top_index == -1;
}

bool Is_full()
{
    return top_index == stack_size - 1;
}

//从顶部开始打印栈元素
void PrintStack(){

    int i = top_index;
    if (i == -1) {
        cout << "the stack is null" << endl;
    }else{
        while (i != -1) {
            printf("%d ",stack[i--]);
        }
        printf("\n");
    }
}
//动态数组实现栈的方式中手动分配栈的内存。
void CreateStack(unsigned int init_size){
    if (stack_size == 0) {
        stack_size = init_size;
        stack = (int*)malloc(stack_size * sizeof(STACK_TYPE));
        if (stack == NULL) {
            cout << "arraty allocation failed" << endl;
        }
    }
}

void DestroyStack(){
    if (stack_size > 0) {
        stack_size = 0;
        free(stack);
        stack = NULL;//数组置空
        top_index = -1;
    }
}
/*链式堆栈，是完全不同于数组方式实现,这和链表的指向也有很大关系，设置栈顶指针永远指向新节点，栈顶节点指向上一个节点*/
typedef struct STACK_NODE
{
    STACK_TYPE value;
    struct STACK_NODE *link;
}StackNode;

static StackNode *stack_top;//定义一个固定的指向栈顶节点的指针

void LPush(STACK_TYPE value)//此处采用了头插法
{
    StackNode *new_node;
    new_node = (StackNode*)malloc(sizeof(StackNode));
    if (new_node != 0)//如果节点分配内存成功就把它放在栈顶的位置,也就是说栈顶指针一定一直指向新节点
    {
        new_node -> value = value;
        new_node -> link  = stack_top;
        stack_top = new_node;
    }
}
void LPop(void)
{
    if (!LIs_empty())
    {
       stack_top = stack_top->link;
    }
}
STACK_TYPE LTop(void)
{
    if (!LIs_empty())
    {
        return stack_top -> value;
    }
}

bool LIs_empty(void)
{
    return stack_top == 0;

}
void LDestoryStack(void)
{

    while (!LIs_empty())
    {
        LPop();
    }
    cout << "the stack is empty!"<<endl;
}
void LPrintStack()//从栈顶输出
{
    StackNode *top;
    top = stack_top;
    while (top != 0)
    {
        cout << top->value <<endl;
        top = top->link;
    }
}
