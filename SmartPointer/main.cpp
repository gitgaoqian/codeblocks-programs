#include <iostream>
#include <memory>
using namespace std;


//基于引用计数实现的自定义只能指针类,其效果类似shared_ptr:支持拷贝构造和赋值,这两项操作均会导致计数器加1
//参考:https://www.cnblogs.com/QG-whz/p/4777312.html#_label2
//class Point
//{
//public:
//    Point(int xVal = 0, int yVal = 0) :x(xVal), y(yVal) { }
//    int getX() const { return x; }
//    int getY() const { return y; }
//    void setX(int xVal) { x = xVal; }
//    void setY(int yVal) { y = yVal; }
//    int a = 100;
//
//private:
//    int x, y;
//
//};
//template <typename T>
//class SmartPtr;
//
//template <typename T>
//class U_Ptr//辅助类,仅作为封装计数器Count和父类指针*p;
//{
//    private:
//        friend class SmartPtr<T>;
//        U_Ptr(T *ptr):p(ptr),Count(1){}
//        ~U_Ptr(){delete p;}
//
//        int Count;
//        T *p;
//};
//template <typename T>
//class SmartPtr
//{
//    public:
//        SmartPtr(T *ptr):rp(new U_Ptr<T>(ptr)){};
//        SmartPtr(const SmartPtr<T> & sp):rp(sp.rp){++rp->Count;}
//        SmartPtr & operator =(const SmartPtr<T> & rhs)
//        {
//            ++rhs.rp->Count;
//            if(--rp->Count == 0)//不懂
//            {
//                delete rp;
//            }
//            rp=rhs.rp;
//            return *this;
//
//        }
//        ~SmartPtr()
//        {
//            if(--rp->Count == 0)
//                delete rp;
//            else
//                cout <<"还有"<< rp->Count << "  个指针指向基础对象" << endl;
//        }
//        T & operator *()//由于rp是私有成员,类对象不能直接访问,所以这里重载操作符来间接访问rp从而访问基础对象的成员.
//        {
//            return *(rp->p);
//        }
//        T * operator ->()
//        {
//            return rp->p;
//        }
//
//    private:
//        U_Ptr<T> *rp;
//
//
//};
//
//int main()
//{
//    //定义一个基础对象类指针
//    Point *pa = new Point(10, 20);
//
//    //定义三个智能指针类对象，对象都指向基础类对象pa
//    //使用花括号控制三个指针指针的生命期，观察计数的变化
//
//    {
//        SmartPtr<Point> sptr1(pa);//此时计数count=1
//        {
//            SmartPtr<Point> sptr2(sptr1); //调用复制构造函数，此时计数为count=2
//            {
//                SmartPtr<Point> sptr3=sptr1; //调用赋值操作符，此时计数为conut=3
//            }
//            //此时count=2
//        }
//        //此时count=1；
//    }
//    //此时count=0；pa对象被delete掉
//
//    cout << pa->getX ()<< endl;
//    return 0;
//}

//shared_ptr的利用
int main()
{
    int *ip = new int(20);
    {
        shared_ptr<int>  ptr1(ip);
    {
        cout << ptr1.use_count()<< endl;
        shared_ptr<int> ptr2(ptr1);
        cout << ptr2.use_count()<< endl;
        {
            shared_ptr<int> ptr3 = ptr2;
            cout << ptr3.use_count()<< endl;
        }
        cout << ptr2.use_count() << endl;
    }
    cout << ptr1.use_count()<< endl;
    }

}


