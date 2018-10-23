#include<stdio.h>
#include<iostream>
using namespace std;

class A
{
    public:
        int i;
        A();//构造函数:函数名和类名相同.为了进行对象初始化,在对象创建是调用
        ~A();//析构函数,函数名和类名相同,并在前面加一个~号,在对象退出时调用
        virtual void Subtract(int m);
        void PublicAdd(int m);
    private:
        int j;
        int PrivateAdd(int m);

};
A::A():i(10),j(10)  //此处是直接进行了初始化列表操作,这和在构造函数内部进行赋值操作的结果是一样的.但是推荐用这种方法进行初始化操作
{
//    printf("A::A--initial: i = %d\n",i);
//    printf("A::A--initial: j = %d\n",j);
//    printf("i -- %x\n",&i);//从中窥探:第一个输出的变量的地址就是类的对象的地址;
//    printf("this--%x\n",this);//this指向的地址就是对象的地址
}
A::~A()
{
//    printf("A:~A--release: i = %d\n",i);
}
void A::Subtract(int m)
{
    i  = i - m;
//    printf("A::Substract--public: i = %d\n",i);
    cout << "A::Subtract" << i <<endl;
}
void A::PublicAdd(int m)
{
    i = PrivateAdd(m);
    //printf("A::Add--public:i = %d\n",i);

}
int A::PrivateAdd(int m)
{
    i = i + m;
    return i;
}

class B: public A
{
   public:
        void Subtract(int m)
        {
            i = i - m -1;
            cout << "B::Subtract: "<< i << endl;
        }
};
int main()
{
    //类和结构体十分相似，所以访问类成员的方式：使用对象的直接访问方式（.操作符）和使用指针的间接访问（->操作符）。
    A a; //声明类的对象
    A *ap = &a;//声明指向对象的指针
    B b;
    B *bp;

//    cout << "a.i=" << a.i << " "<< "b.i=" << b.i << endl;
//    cout << "sizeof(A)="<<sizeof(A) << " "<<"sizeof(B)="<<sizeof(B) << endl;
//    a.Subtract(1);
//    cout << "after substract,ap->i=" << ap->i <<endl;
//    a.PublicAdd(2);
//    cout << "after add,ap->i=" << ap->i << endl;


    //多态
    a.Subtract(1);
    b.Subtract(1);

//    ap->Subtract(1);
//    bp->Subtract(1);
//



}


