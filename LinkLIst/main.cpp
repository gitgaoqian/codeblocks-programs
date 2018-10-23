#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
using namespace std;

//声明链表节点的结构体
typedef struct NODE
{
    struct NODE *link;
    int value;
}Node,*LinkList; //Node 表示节点,Linklist可以看做是一个链表

static Node *head_node;//设置头指针,目的为了进行链表的操作

Node * CreateList(int n);
void CreateListTail(LinkList *L, int n);
void Insert(Node **linkp,int new_value);
void PrintList();

int main()
{
    Node *rootp;//此处不能在声明句初始化，而是利用了赋值操作，具体原因不明
    rootp = CreateList(10);

//     LinkList l;
//     CreateListTail (&l,10);
//    struct NODE node3 = {NULL,15};
//    struct NODE node2 = {&node3,10};
//    Node node1={&node2,5};
//    Node *rootp = &node1;

    cout << "Before Insert,the rootp:"<<rootp << endl;
    PrintList();
    cout << "Before Insert,THE FIRST VALUE:"<<rootp->value << endl;
    Insert(&rootp,30);
    cout << "After Insert,the rootp:"<<rootp << endl;
    cout << "Afer Insert,THE FIRST VALUE:"<<rootp->value << endl;

}
//链表初始化
Node * CreateList(int n)
{
    //定义三个链表节点并且初始化,这种初始化方式不行
//    struct NODE node3 = {NULL,15};
//    struct NODE node2 = {&node3,10};
//    Node node1={&node2,5};
//    Node *rootp = &node1;
//    return rootp;//返回根指针
//用下面这种方式初始化，需要手动分配内存

//    Node *node3 = (Node*)malloc(sizeof(Node));
//    node3->link = 0;
//    node3->value = 10;
//    Node *node2 = (Node*)malloc(sizeof(Node));
//    node2->link = node3;
//    node2->value = 8;
//    Node *node1 = (Node *)malloc(sizeof(Node));//设置头指针,目的为了进行链表的操作
//    node1->link = 0;
// 随机创建线性表:
    head_node = (Node *)malloc(sizeof(Node));
    head_node->link = 0;
    head_node->value = 10;
    Node *p = head_node;
    for (int i=0;i<n;i++)//随机创建10个新节点,并采用尾插法.
    {
        Node *new_list = (Node*)malloc(sizeof(Node));
        new_list->value =  rand() % 100 + 1;//随机产生1-100的数据
        new_list->link = 0;

        p->link = new_list;
        p = new_list;
    }
//
//    cout << "node1 adress:"<<&node1 << endl;
//    cout <<"node2 adress:"<<&node2 << endl;
//    cout <<"node3 adress:"<< &node3 <<endl;
//    cout << " "<< endl;

    return head_node;//返回头指针

}
//另一种创建表的方法
void CreateListTail(LinkList *L, int n)
{
    LinkList p,r;
    int i;
    *L = (LinkList)malloc(sizeof(Node));
    head_node = *L;
    r = *L;
    for (i=0;i<n;i++)
    {
        p = (Node *)malloc(sizeof(Node));
        p->value = rand()%100+1;
        r->link = p;
        r = p;
    }
    r->link = 0;

}

//链表插入操作,参考《c和指针》链表插入程序的最终版https://blog.csdn.net/u011601005/article/details/52099497
void Insert(Node **linkp,int new_value)
//由于可能需要对链表的根指针进行操作，所以我们一般把第一个函数参数linkp设为指向指针的指针，它的初始值指向根指针，同样也可以指向节点内部的指针。参数new_value表示插入的新值
{
    Node *current;//声明一个指针指向当前节点
    Node *New;//声明指针指向新节点，新节点需要进行内存分配
    current = *linkp; //把初始值根指针付给current，表示从根指针开始对链表进行顺序遍历。
    while (current->value < new_value && current != 0)
    {
        //cout << current->value <<endl;
        linkp = &(current->link);//把当前节点内部的指针的地址赋值给linkp
        current = current->link;//把下个节点的地址赋值给current

    }

    New = (Node *)malloc(sizeof(Node));
    if (New == NULL)//内存分配失败
        cout << "内存分配失败" << endl;
    //插入新的值
    New -> value = new_value;
    New -> link = current;
    *linkp = New;//由于*linkp是指向rootp的指针，他的改变会引起rottp的改变，但是实际中只有当链表插入头部元素时，*Linkp和rootp才会一样，这是为什么？
    cout << "*linkp:"<<*linkp<<endl;
    cout << "New Node Adress:" << New << endl;
    cout << "NEW->VALUE:"<<New-> value <<endl;
    cout <<"NEXT->VALUE:"<< current->value << endl;
}
void PrintList()
{
    while (head_node!=0)
    {
        cout << head_node->value <<endl;
        head_node = head_node->link;
    }

}
