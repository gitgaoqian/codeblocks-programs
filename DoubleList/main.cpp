#include <stdio.h>

typedef struct NODE
{
    int value;
    struct NODE *piror;
    struct NODE *next;
}Node,*LinkList;

LinkList CreateList(int n);
void Insert(int n);
static Node *head;
static Node *tail;//设置head,tail指向第一个元素和最后一个元素。当然第一个元素是头指针，没有数据
int main()
{
    CreateList(10);
}

void CreateList(int n)
{
    head->prior = 0


}
