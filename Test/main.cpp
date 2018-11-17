#include <iostream>
#include <string.h>
using namespace std;

class Person
{
    public:
        void GetName();
        void GetHight();
        virtual void GetAge();
        static void AgeGet();
        Person();
        Person(const char *name,int height,int age);
        Person(const Person &per);
        Person operator+(const Person &per);
        friend void GetInfo();
    private:
        static int value;
        int age = 24;
        int hight = 180;
        char name[10]= {'a','b','c','\0'};

};
int Person::value = 10;
Person::Person()//无参构造函数
{

}
Person::Person(const char *n,int h,int a)//构造函数重载
{
    strcpy(name,n);
    hight = h;
    age = a;
}

Person::Person(const Person &per)//拷贝构造函数
{
    age = per.age + 1;
    hight = per.hight + 5;
    strcpy(name,"WHO");
}

Person Person::operator+(const Person &per)//操作符重载
{
    Person Per;
    Per.age = this->age + per.age;
    Per.hight = this->hight + per.hight;
    return Per;

}
void Person::GetAge()
{
    cout << "age:" << Person::age << endl;
}

void Person::GetHight()
{
    cout << "height:" << Person::hight << endl;
}

void Person::GetName()
{
    cout << "name:" << Person::name << endl;
}
void Person::AgeGet()
{
    cout << "static Person::AgeGet function:"<< Person::value<<endl;
}
void GetInfo(Person &p)
{
    p.GetAge();
    p.GetName();
    p.GetHight();
}


class Student:public Person
{
    public:
        Student(int val):age(val){}
        virtual void GetAge(){cout << "stu:" << age << endl;}
    private:
        int age;

};
void GetAge(Person per)
{
    per.GetAge();

}
void getage(Person &per)
{
    per.GetAge();

}


int main()
{
    char name[] = "gaoqian";
    int age = 23;
    int height = 183;

    Person::AgeGet();

    Student stu(10);
    Person per = stu;//用子类对象来初始化父类对象不存在多态(注意多态条件),子类对象赋值给父类对象，仅仅把继承自父类部分成员函数赋值给父类对象.此时的父类对象动态绑定的依旧是自己的方法.初始化时,调用拷贝构造函数
    per.GetAge();

    GetInfo(per);



//    GetAge(stu);//函数采用值传递,在临时对象per中会调用Person的拷贝构造函数.
//    getage(stu);//函数参数是引用,不会产生新的临时对象

//    Person per1(per);
//    per.GetAge();
//    per.GetHight();
//    per.GetName();
//
//    per1.GetAge();
//    per1.GetHight();
//    per1.GetName();
//
//    Person per2 = per1 + per;
//    per2.GetAge();
//    per2.GetHight();

}
