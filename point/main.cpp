//案例1：
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

//用指针实现字符串库函数
//1.字符串链接
//char* _strcat(char* dest, const char* src)
//{
//    char* tmp = dest;
//    while (*tmp)//若为while(*dest++)则会跳过dest中的'\0'导致无法连接
//        tmp++;
//    while (*tmp++ = *src++);
//    return dest;
//}
//char * my_strncat(char *dest,const char * src,int n)
//{
//    char *temp = dest;
//    while(*temp)
//        temp++;
//    while((n--) && (*src))
//        *temp++ = *src++;
//    return dest;
//
//
//}
////2.字符串比较
//int _strcmp(const char *src,const char *dest)
//{
//    while (*dest++ == *src++);
//    if (*dest > *src)
//        return 1;
//    else
//        return 0;
//}
//3 找到src字符串第一次出现在目标字符串的位置 _-strstr???
//char *my_strstr(const char *cs,const char *ct)
//{
//    const char *s = cs;
//    const char *t = ct;
//    for(; *cs != '\0';cs++) {
//        for(s = cs,t = ct;*t != '\0' && *s == *t;s++,t++);
//        if(*t == '\0')
//            return (char *)cs;
//    }
//    return NULL;
//}
//char *my_strstr2(const char *dest,const char *src)
//{
//    const char *dest_temp = dest;
//    const char *src_temp = src;
//    while(*src)
//    {
//        src_temp = src;
//        dest_temp = dest;
//        while(*src_temp == *dest_temp)
//        {
//            src_temp++;
//            dest_temp++;
//        }
//        if(*dest_temp == '\0')
//        {
//            return (char *)src;
//        }
//        src++;
//    }
//}

//4 字符串复制
//void my_cpy(char *dest,char *src)
//{
//    char *temp = dest;
//    while(*src)
//    {
//        *temp++ = *src++;
//    }
//
//    temp = '\0';
//    printf("%s\n",dest);
//}

//void my_strncpy(char *dest,char *src,int n)
//{
//    char *temp = dest;
//    while((n--)&&(*src))
//    {
//        *temp++ = *src++;
//    }
//    printf("%s\n",dest);
//
//}
//int a = 10;
//char *sub;
////5 字符串分割,返回分解后的第一个字符串
//char * my_strtok(char *dest,char *src)
//{
//    char *s;
//    if (dest != NULL)//第一次调用
//    {
//        char *p = dest;
//        while(*p != '-')
//            p++;
//        *p = '\0';
//        s = dest;
//        sub = ++p;
//        a = a+1;
//        return s;
//    }
//    char *q = sub;
//    while (*q != '-')
//        q++;
//    *q = '\0';
//    s = sub;
//    sub = ++q;
//    return s;
//
//}
//
//
//
//int main()
//{
//
//   char src[] = "abg-ja-bc-djf-i";
//    char dest[] = "bcd";
//    char seg[] = "-";
//    char *p = my_strtok(src,seg);
//    printf("%s\n",p);
//    p = my_strtok(NULL,seg);
//    printf("%s\n",p);
//
//
////    my_cpy(s2,s1);
////    my_strncpy(dest,src,5);
////    char *p = _strcat(s1,s2);
////    char *p = my_strncat(dest,src,6);
////    int a = _strcmp(s1,s2);
////     my_strstr(s1,s2);
////      char *p = my_strstr2(dest,src);
////      printf("%s",p);
//
//}

//int main()
//{
//    int a=6000;
//    char *s=(char*)&a;
//    char c;
//    c=*(s+3);*(s+3)=*(s+0);*(s+0)=c;
//    c=*(s+2);*(s+2)=*(s+1);*(s+1)=c;
//    printf("%d",a);
//}

//案例2 -- 统计不同字符串包含同一字母的个数，两种思路：一种通过设置一个结构体类型指针和字符型指针；另一种是设置指针数组，分别指向不同的字符串；下面介绍第一种方法
//typedef struct{
//    char value[20];
//}String;//结构体定义类型
//int Count (String *p,char dst);
//int main()
//{
//    int c;
//    String s[3];//定义三个字符串，并给每个字符串赋值
//    strcpy( s[0].value, "abc");
//    strcpy( s[1].value, "dcfg");
//    strcpy( s[2].value, "hickl");
//    String *sp = s;//定义结构体类型指针
//    char dst = 'c';
//    c = Count(sp,dst);
//    cout << c << endl;
//
//}


//int Count(String *sp,char dst)
//{
//    int c=0;
//    char *cp;//定义char类型指针
//    while (*sp->value != '\0')
//    {
//         cp=(char*)sp;
//         while (*cp != '\0')
//         {
//            if (*cp == dst)
//            {
//                c++;
//            }
//            cp++;
//         }
//         sp++;
//    }
//    return c;
//}
//
////
////案例3：删除字符串中的特定部分
////*********************************************************************************
////【功能】在给定字符串中查找所有特定子串并删除，如果没有找到相应子串，则不作任何操作。
////【思路】将不是子串的字符拷贝。
////********************************************************************************
//#include <iostream>
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//using namespace std ;
//
//int del_sub(char *str, char *sub)
//{
//    char *psrc = str, *pdest = str;  //两个指针都指向str，将psrc指向的字符按规则挑出来给pdest
//	char *p,*psub;
//	char count=0;
//
//   if((str == NULL) || (sub == NULL))
//       return 0;
//
//   while(*psrc)
//   {
//       p = psrc;
//       psub = sub;
//       while(*p && *p == *psub)
//       {
//           p++;
//           psub++;
//       }
//
//       if(*psub == 0)//找到一个子串
//        {
//			psrc = p;
//			count++;
//		}
//	   else
//           *pdest++ = *psrc++;
//   }
//   *pdest = 0;
//   return count;
//}
//void Input(char *src,char *sub)
//{
//
//    printf("Input the first string:");                                 //输入字符串
//    scanf("%s",src);
//    printf("\nInput the second string:");                        //输入字符串
//    scanf("%s",sub);
//}
//int main()
//{
//	int num;
//	char str[20];
//	char sub[20];
//	Input(str,sub);
//	cout<<"first str = "<<str<<endl;
//	cout<<"sub str = "<<sub<<endl;
//	num = del_sub(str,sub);
//	cout<<"number = "<<num<<endl;
//	cout<<"new str = "<<str<<endl;
//	return 0;
//}
//案例4--指向整形的指针和指向数组的指针以及数组名的含义
//int main()
//{
//    int b[3] = {1,2,3};
//    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
//    int *bp=b;//声明指向整形的指针
//    int (*ap)[4] = a;//声明指向整形数组的指针
//    cout << *(bp+1)<<endl;
//    cout << *(*(ap+1)+2) <<endl;//对指向数组的指针进行间接操作表示获取这个数组，并得到该数组的首地址
//    cout << b << " " << b+1 <<endl;//数组名b表示指向第一个整形元素，b+1表示指向第二个元素
//    cout << *b << " "<< *(b+1) << endl;
//    cout << a << " " << a+1 <<endl;//数组名a表示指向第一行（即包含4个元素的数组）的指针，a+1指向第二行。*a表示指向第一行第一个元素的指针，*（a+1）表示指向第二行第一个元素的指针
//    cout << **a << " "<< **(a+1) << endl;
//}
//案例：结构体和结构体指针
typedef struct {
    int a;
    char b[3];
    short c[3];
}S1,*SP;
typedef struct {
    int a;
    char b[4];
    int c[4];
    S1 *p;
}S2;
int main()
{
    S1 s1 = {2,"de",{5,6,7}};
    S1 *p1 = &s1;
    S2 s2 = {1,"abc",{1,2,3,4},p1};
    S2 *p2 = &s2;//声明指向结构的指针
    SP sp = p1;
    cout << (*sp).b << endl;
//    cout << sizeof(S1) << endl;
//    cout << sizeof(S2) << endl;
//    cout << s1.a<<" "<<(*p1).a<<" "<< p1->a<< endl;//结构的直接访问和间接访问：对指向结构的指针执行间接操作表示获得这个结构。
//    cout << p2->p->a << endl;

}
