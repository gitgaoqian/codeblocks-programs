//Linklist2相对于linklist更改了内容:不再设置全局变量的根指针.而是把其作为一个参数.这样的程序具有通用性.

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
}Node,*LinkList; //Node 表示节点,Linklist可一个链表


LinkList CreateListTail(int n);//创建包含n个数据的链表，并且该链表设置了头指针。该函数返回头指针
LinkList CreateCircleList(int n);//创建循环链表
void InsertNode(LinkList L,int i,int new_value);
void PrintList(LinkList L);
void DeleteNode(LinkList L,int i);
void ClearList(LinkList L);//创建普通链表


int main()
{
//     LinkList L = CreateListTail(10);//创建带头结点的链表,希望头结点永远不动
//     PrintList(L);
//     InsertNode(L,3,108);
//     PrintList(L);
//     InsertNode(&L,3,40);
//     cout << "After Insert:"<<endl;
//     PrintList(L);
//     DeleteNode(L,5);
//     cout << "After Delete:"<< endl;
//     PrintList(L);
//     ClearList(&L);
//     cout << "After Clear:"<< endl;
//     PrintList(L);
//     PrintList(L);
        LinkList L = CreateCircleList(10);
        PrintList(L);

}
//创建包含头结点的链表,尾插法
LinkList CreateListTail(int n)
{
    LinkList L,p,r;
    L = (Node *)malloc(sizeof(Node));
    L->link = 0;
    r = L;
    for(int i=0;i<n;i++)
    {
        p = (Node *)malloc(sizeof(Node));
        p->value= rand()%100+1;
        r->link = p;
        r = p;
    }
    r->link = 0;
    return L;

}
LinkList CreateCircleList(int n)
{
    LinkList L,p,new_node;
    L = (Node *)malloc(sizeof(Node));
    L->link = 0;
    p = L;
    for (int i=0;i<n;i++)
    {
        new_node = (Node *)malloc(sizeof(Node));
        p->value = rand()%100+1;
        p->link = new_node;
        p = new_node;
    }
    p->link = L;
    return L;

}

//插入到第i个位置
void InsertNode(LinkList L,int i,int new_value)
{
    LinkList current,New;
    int j;
    j=1;
    current = L;//把初始值根指针付给current，表示从根指针开始对链表进行顺序遍历。
    while (current && j<i)
    {
        current = current->link;//把下个节点的地址赋值给current
        j++;

    }

    if (!current || j>i)
        cout << "the i potion not exist" << endl;
    else
    {
        New = (LinkList)malloc(sizeof(Node));
        if (New == 0)//内存分配失败
            cout << "内存分配失败" << endl;
        //插入新的值
        New -> value = new_value;
        New -> link = current->link;
        current->link = New;
        cout << "New Node Adress:" << New << endl;
        cout << "NEW->VALUE:"<<New-> value <<endl;
        cout <<"NEXT->VALUE:"<< New->link->value << endl;

    }

}
//删除第i个位置的结点
void DeleteNode(LinkList L,int i)
{
    LinkList current,p;//curent记录当前结点,p记录上一个结点
    int j;
    j=1;
    current = L;//把初始值根指针付给current，表示从根指针开始对链表进行顺序遍历。
    while (current && j<i)
    {
        p = current;
        current = current->link;
        j++;

    }

    if (!current || j>i)
        cout << "the i potion not exist" << endl;
    else
    {
        p->link = current->link;
        free(current);//收回结点内存
    }
}
void PrintList(LinkList L)
{
    Node *p= L->link;
    if (p==0)
        cout << "the linklist has no node"<< endl;
    while (p!=0)
    {
        cout << p->value <<endl;
        p = p->link;
    }

}
void ClearList(LinkList L)
{

    LinkList p,q;
    p = L;
    while (p)
    {
        q = p->link;
        free(p);
        p = q;
    }
    L->link = 0;//设置头结点指向空
}

