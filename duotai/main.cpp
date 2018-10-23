
#include <iostream>
#include <typeinfo>
using namespace std;

class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      virtual int area()//设置函数为动态绑定，即绑定的是对象的动态类型
      {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};
class Rectangle: public Shape{
   public:
      Rectangle( int a=0, int b=0):Shape(a, b) { }
      int area ()
      {
         cout << "Rectangle class area :" <<endl;
         return (width * height);
      }
};
class Triangle: public Shape{
   public:
      Triangle( int a=0, int b=0):Shape(a, b) { }
      int area ()
      {
         cout << "Triangle class area :" <<endl;
         return (width * height / 2);
      }
};
// 程序的主函数
int main( )
{
    Rectangle rec(10,7);
    Triangle  tri(10,5);
    Shape shape(10,10);
    Shape *pshape;//静态类型为Shape*,动态类型为Shape*;静态类型不可改变，动态类型可以改变


   shape.area();
   rec.area();
   tri.area();

    pshape = &shape;
    pshape->area();
    cout << typeid(pshape).name() << endl;////获取指针类型
    cout << typeid(*pshape).name() << endl;////获取指针指向对象的类型
   // 存储矩形的地址
    pshape = &rec;//此时动态类型为Recatangle，此时调用矩形的求面积函数 area
    pshape->area();
     cout << typeid(*pshape).name() << endl; //获取指针指向的对象的类型，当基类中有virtual函数时，指向的对象是子类；否则是基类
   // 存储三角形的地址
   pshape = &tri;//此时动态类型为Triangle，此时调用三角形的求面积函数 area
   pshape->area();
    cout << typeid(*pshape).name() << endl; //获取指针指向的对象的类型


}
