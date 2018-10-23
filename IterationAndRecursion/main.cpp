//https://blog.csdn.net/ymqcs/article/details/51829154
//递归包含两层意思:递归调用,逐级返回
#include<stdio.h>
//有去有回的案例
void up_and_down(int);

int  main(void)
{
up_and_down(1);
return 0;
}


void up_and_down(int n)
{
printf("level %d: n loacation %p\n", n, &n);/*1*/
if (n < 4)
up_and_down(n + 1);//递归函数
printf("level %d: n loacation %p\n", n, &n);/*2*///归来执行语句

}


