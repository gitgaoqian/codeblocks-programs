#include <stdio.h>
#include "Queue.h"
#include <iostream>
using namespace std;
/*利用不完全填满技巧*/
/*静态循环数组实现方式测试代码*/
//int main()
//{
//    Insert(4);Insert(6),Insert(5),Insert(7);
//    PrintQueue();
//    printf("\n");
//
//    Delete();
//    printf("After delete:\n");
//    PrintQueue();
//    printf("\n");
//    printf("the font element is:%d\n",First());
//    return 0;
//}

/*动态循环数组的实现方式*/
//int main()
//{
//    CreateQueue(8);
//    Insert(4);Insert(6),Insert(5),Insert(7);Insert(4);Insert(6),Insert(5);
//    PrintQueue();
//    printf("\n");
//
//    Delete();Delete();Delete();
//    printf("After delete:\n");
//    PrintQueue();
//    printf("\n");
//    printf("the font element is:%d\n",First());
//    return 0;
//
//}
/*链式队列实现方式*/
int main()
{
    LInitial();
    LInsert(4),LInsert(5),LInsert(3);LInsert(6);
    cout << "After Insert:"<<endl;
    LPrintQueue();
    cout << "The queue head:"<<LQueueFont()<<endl;
    cout << "After Delete:"<<endl;
    LDelete();
    LPrintQueue();
    cout << "The queue head:"<<LQueueFont()<<endl;
    cout << "After Destroy:"<<endl;
    LDestoryQueue();
    LPrintQueue();

}
