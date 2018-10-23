#include <iostream>

using namespace std;

class A
{
    public:
        A() { cout<<"A Constructor"<<endl; }
        ~A() { cout<<"A Destructor"<<endl; }
        void fun() { cout<<"A Function"<<endl; }
        void funA() { cout<<"A FunctionA"<<endl; }
};

class AA : public A
{
    public:
        AA() { cout<<"AA Constructor"<<endl; }
        ~AA() { cout<<"AA Destructor"<<endl; }
        void fun() { cout<<"AA Function"<<endl; }
        void funA() { cout<<"AA FunctionA"<<endl; A::fun(); A::funA(); }
};

class B
{
    public:
        B() { cout<<"B Constructor"<<endl; }
        virtual ~B() { cout<<"B Destructor"<<endl; }
        virtual void fun() { cout<<"B Function"<<endl; }
        virtual void funB() { cout<<"B FunctionB"<<endl; }
};

class BB : public B
{
    public:
        BB() { cout<<"BB Constructor"<<endl; }
        ~BB() { cout<<"BB Destructor"<<endl; }
        void fun() { cout<<"BB Function"<<endl; }
        void funB() { cout<<"BB Function"<<endl; B::fun(); B::funB(); }
};


/*-----------------------------------------------------------------------------
 *  测试普通继承下，构造函数与析构函数顺序
 *-----------------------------------------------------------------------------*/
void test1()
{
    A *a = NULL;
    AA *aa = NULL;
    B *b = NULL;
    BB *bb = NULL;

    aa = new AA();
    aa->fun();
    delete aa;
    cout<<"======================="<<endl;
    bb = new BB();
    bb->fun();
    delete bb;
}


/*-----------------------------------------------------------------------------
 *  测试子类转换为父类后，构造函数与析构函数顺序
 *-----------------------------------------------------------------------------*/
void test2()
{
    A *a = NULL;
    AA *aa = NULL;
    B *b = NULL;
    BB *bb = NULL;

    a = new AA();
    a->fun();
    delete a;
    cout<<"======================="<<endl;
    b = new BB();
    b->fun();
    delete b;
}
/*-----------------------------------------------------------------------------
 *  测试虚函数调用
 *-----------------------------------------------------------------------------*/
void test3()
{
    AA *aa = NULL;
    B *b = NULL;

    aa = new AA();
    aa->funA();
    delete aa;
    cout<<"======================="<<endl;
    b = new BB();
    b->funB();
    delete b;
}

int main()
{
    test3();
}

