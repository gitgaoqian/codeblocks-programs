#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
using namespace std;
//
//typedef struct
//{
//    int a;
//    int b;
//    char c;
//
//} Struct;
//
//Struct * Initial();
//
//int main()
//{
////    Struct *p;
////    p = Initial();
////
////    cout << p << endl;
////
////    cout << p->a<< endl;
////    cout << p->b << endl;
////    cout << p->c << endl;
////    free(p);
//    char a[] = "abcdfjdlfa";
//    printf("%10s","abcd");
//
//}
//
//Struct * Initial ()
//{
//    Struct s2 = {3,4,'b'};
//    Struct *sp = (Struct*)malloc(sizeof(Struct));
//    sp->a = 1;
//    sp->b = 2;
//    sp->c = 'a';
//    Struct *sp2 = &s2;
//    cout << sp << endl;
//    return sp;
//
//}


/* 把字符串的*号提前,其余字符位置保持不变*/
//#include<stdio.h>
//#include<iostream>
//
//using namespace std;

//void sortFun(char *p)
//{
//    int i = 3;
//    char temp = p[i];
//    int j;
//    while ( p[i]!=0 )
//    {
//        if(p[i] == '*')
//        {
//            char tmep = p[i];
//            for (j=i-1; j >= 0;j--)
//            {
//                p[j+1] = p[j];
//            }
//            p[0] = temp;
//
//        }
//        i++;
//
//    }
//
//}
//
//
//int main()
//{
//    char a[] = "abc*d**fg*h";
//    cout << a<< endl;
//    sortFun(a);
//    cout << a << endl;
//
////}
//
//给定一个正整数n,你的任务是最少的操作次数把序列1 2 3 4 5...n中所有的数字都变成0，每次操作可以从序列中选择一个活多个整数，同时减去一个相同的正整数，比如
//1 2 3可以吧2和3同时减少2，得到1 0 1*/
//#include<stdio.h>
//#include<math.h>
//
//int F(int n)//递归方式
//{
//    return n == 1 ? 1 : F(n/2) + 1;
//}
//int FF(int n)//迭代方式
//{
//    int num = 0;
//    while (ceil(n/2)!=0)
//    {
//        num++;
//        n=ceil(n/2);
//    }
//    return (num+1);
//}
//
//
//
//int main ()
//{
//    int n = 37434;
//    printf("%d\n" ,F(n));
//    printf("%d\n",FF(n));
//    return 0;
//}
//输入字符串，然后逆序输出
//#include<stdio.h>
//int main()
//{
//    char a[100];
//    scanf("%s",a);
//    char *p = a;
//    while (*p != '\0')
//    {
//        p++;
//    }
//    printf("\n");
//    while (p!=a)
//        printf("%c",*(--p));
//
//
//}

//c语言中冒号表示位域
// union V {
// struct X {
// unsigned char s1:2;//结构体中的冒号表示位域。位域出现的原因是由于某些信息的存储表示只需要几个bit位就可以表示而不需要一个完整的字节，同时也是为了节省存储空间和方便处理。
// unsigned char s2:3;
// unsigned char s3:3;
// }x;
// unsigned char c;
// } v;
//int main()
//{
//v.c = 200;
//printf("%d", v.x.s3);
//
//}
//int add()
//{
//    static int c=10;
//    return c--;
//}
//int sub()
//{
//    static int c=1;
//    return c++;
//}
//int main()
//{
//        static int c = 1;
//        for(;c < 10; c++)
//        {
//            printf("%d   %d\n",sub(),add());
//
//        }
//}

struct Day
{
    Day(int d):val(d){}
    int val;
};
struct Month
{
    Month(int m):val(m){}
    int val;
};
struct Year
{
    Year(int y):val(y){}
    int val;
};

class Date
{
    public:
        static
        Date(const Month &m,const Day &d,const Year &y);

};
int main()
{
    Month m(3);
    Day d(3);
    Year y(1994);
    Date date(m,d,y);

}










