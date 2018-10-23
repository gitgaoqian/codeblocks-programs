//回文字符串检测
#include <stdio.h>
#include <iostream>
using namespace std;
//int FindSubString( char* pch )
//{
//    cout << "p1: "<< pch << endl;
//    int   count  = 0;
//    char  * p1   = pch;
//    while ( *p1 != '\0' )
//    {
//        if ( *p1 == p1[1] - 1 )
//        {
//            p1++;
//            count++;
//        }else  {
//            break;
//        }
//    }
//    int count2 = count;
//    while ( *p1 != '\0' )
//    {
//        if ( *p1 == p1[1] + 1 )
//        {
//            p1++;
//            count2--;
//            //cout << "p1 == p1[1] + 1 " << *p1 << endl;
//
//        }else  {
//            break;
//        }
//    }
//    cout << count <<" "<< count2 << endl;
//    if ( count2 == 0 )
//        return(count);
//    return(0);
//}
//void ModifyString( char* pText )
//{
//    char  * p1   = pText;
//    char  * p2   = p1;
//    while ( *p1 != '\0' )
//    {
//        int count = FindSubString( p1 );
//        if ( count > 0 )
//        {
//            *p2++ = *p1;
//            sprintf( p2, "%i", count );
//            cout << "p2: "<< p2 << endl;
//            while ( *p2 != '\0' )
//            {
//                p2++;
//            }
//
//            p1 += count + count + 1;
//        }else  {
//            *p2++ = *p1++;
//        }
//        cout << "p2: "<< p2 << endl;
//    }
//}
//int main( void )
//{
//    char text[32] = "XYBCDCBABABA";
//    ModifyString( text );
//    printf( text );
//}
int main()
{
    signed char a = 0xe0;
    unsigned int b = a;
    unsigned char c = a;
    cout << a << endl;
    cout << int(a) << endl;
    cout << b << endl;
    cout << c <<endl;
}
