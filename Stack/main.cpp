#include <iostream>
#include <stdio.h>
#include "stack.h" //用“”是在当前目录下寻找，用<>在自己定义的路径寻找在setting中的complier选项中添加头文件的路径
using namespace std;

/*https://blog.csdn.net/chenyufeng1991/article/details/50812489*/
/*静态数组实现方式测试代码*/
//int main()
//{
//    Push(4);Push(6);Push(1);Push(9);Push(2);Push(8);
//    PrintStack();
//    printf("\n");
//
//    Pop();Pop();Pop();
//    printf("经过pop后栈的元素为:\n");
//    PrintStack();
//    printf("\n");
//    printf("top元素的值:%d\n",Top());
//    return 0;
//}

/*动态数组实现方式测试代码*/
int main()
{
    CreateStack(10);//动态数组实现的第一步，就是分配一定的连续空间，并且使得指针指向它。
    PrintStack();

    Push(6);Push(3);Push(9);Push(1);Push(4);
    cout << "After PUSH：" << endl;
    PrintStack();
    Pop();Pop();

    cout << "After POP："<< endl;
    PrintStack();

    printf("The top element:%d\n",Top());

    DestroyStack();
    PrintStack();

    return 0;

}

/*链式堆栈实现方式测试代码*/
//int main()
//{
//    cout << "Initial Stack:"<<endl;
//    LPrintStack();
//    LPush(5);LPush(7);LPush(4);LPush(2);
//    cout << "After PUSH:"<<endl;
//    LPrintStack();//从栈顶开始输出
//    printf("The top element:%d\n",LTop());
//    LPop();
//    LPop();
//    cout << "After POP:"<<endl;
//    LPrintStack();
//    printf("The top element:%d\n",LTop());
//    cout << "After Destroy Stack:"<<endl;
//    LDestoryStack();
//
//
//}
