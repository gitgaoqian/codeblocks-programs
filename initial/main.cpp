#include<stdio.h>
#include<iostream>
using namespace std;

class A
{
    public:
        int i;
        A(int value);//构造函数:函数名和类名相同.为了进行对象初始化,在对象创建是调用
        ~A();//析构函数,函数名和类名相同,并在前面加一个~号,在对象退出时调用
        void Subtract(int m);
        void PublicAdd(int m);
    private:
        int j;
        void PrivateAdd(int m);

};
A::A(int value):i(value),j(value)  //此处是直接进行了初始化列表操作,这和在构造函数内部进行赋值操作的结果是一样的.但是推荐用这种方法进行初始化操作
{

    //i =j = value;
    printf("A::A--initial: i = %d\n",i);
    printf("A::A--initial: j = %d\n",j);
    printf("i -- %x\n",&i);//从中窥探:第一个输出的变量的地址就是类的对象的地址;
    printf("this--%x\n",this);//this指向的地址就是对象的地址
}
A::~A()
{
    printf("A:~A--release: i = %d\n",i);
}
void A::Subtract(int m)
{
    i  = i - m;
    printf("A::Substract--public: i = %d\n",i);
}
void A::PublicAdd(int m)
{
    printf("A::Add--public:j = %d\n",j);
    PrivateAdd(m);
}
void A::PrivateAdd(int m)
{
    i = i + m;
    printf("A::Add--private: i = %d\n",i);
}
int main()
{
    A a(2); //c初始化i值
    cout << "a.i=" << a.i << endl;
    a.Subtract(1); //让i-2
    a.PublicAdd(2);
    //printf("a--%x\n",&a);//输出对象的地址
    //A b[2] = {A(1),A(2)};//类似结构体数组(这里姑且称之为类数组,相当于定义了多个数组),,通过调用类的构造进行初始化.

}

