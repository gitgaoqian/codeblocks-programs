
//vector是典型的类模板,所以在次我们主要学习vector以了解模板
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

////定义一个函数模板，这个函数实现两个数相加，不过摆脱了类型的限制
//template<class T>
//void MIN(T a,T b)
//{
//    if(a < b)
//        cout << a << endl;
//    else
//        cout << b << endl;
//
//}
////函数模板测试主程序
//int main()
//{
//    MIN<int>(1,2);//可以直接给出函数模板的参数类型
//    MIN(23.2,78.0);//也可以只给定实参，模板实参推断出输入的是double类型
//
//}

//类模板测试主程序
void print(int value)
{
    cout << value << ' ';
}
int main()
{
    //顺序容器--vector（动态数组）
    //初始化，初始化有好多方法
    vector<int> v;//定义一个vector实例
    //插入元素
    for(int i=1;i<10;i++)
        v.push_back(i);
    //访问输出元素
    //cout << v[2] <<endl;//vector和dequeue是唯二可以用下标进行访问元素的。
//    cout << v.at(12) << endl;//at访问元素
//    cout << v.front() << endl;
//    cout << v.back() << endl;
//    cout << v.size() << endl;


    //遍历元素，可以利用下标访问，也可以利用迭代器访问，迭代器返回的是对象的引用
    for_each(v.begin(),v.end(),print);//for_each():为容器中的每个元素执行print函数
    cout << endl;
    for_each(v.rbegin(),v.rend(),print);//rbegin()和rend()是reverse迭代器,使得元素能够逆向访问

    vector<int>::iterator  vi = find(v.begin(),v.end(),4);
    cout << endl;

    cout << &*vi << endl;
    vector<int>::reverse_iterator rvi(vi);//定义一个reverse迭代器
    cout << &*rvi << endl;

    deque<int> d;
    for(int i=1;i<=9;++i)
        d.push_back(i);
    deque<int>::iterator di1;
    di1 = find(d.begin(),d.end(),2);
    deque<int>::iterator di2;
    di2 = find(d.begin(),d.end(),7);
    for_each(di1,di2,print);
    cout << endl;
    deque<int>::reverse_iterator rdi1(di1);
    deque<int>::reverse_iterator rdi2(di2);
    for_each(rdi2,rdi1,print);
    cout << endl;

    //ostrame迭代器
    ostream_iterator<int> intWrite(cout,"\n");
    intWrite = 42;
    intWrite = 77;
    intWrite = 99;

    vector<int> vv;
    for( int i=1;i<9;++i)
        vv.push_back(i);
    copy(vv.begin(),vv.end(),ostream_iterator<int>(cout,"<"));
    cout << endl;




    //顺序容器 -- list(双向链表)
//    list<int> l(4);
////    cout << l.front() << endl;
//    //遍历元素
//    list<int>::iterator li;
//    li = l.begin();
//    cout << &*li << endl;
//    cout << &*(++li) << endl;//虽然是++,但是地址并不是只加了4，说明这个不是连续存储的
//    cout << &*(++li) << endl;
//    for(li = l.begin();li != l.end();li++)//这里的++不是只迭代器移动int类型，而是直接表示指向下一个元素，
//    {
//        *li = rand()%100+1;
//    }
//    //双向链表可以头插也可以尾插
//    l.push_front(100);
//    l.push_back(24);
//    li = l.begin();
//    //在特定的元素前面插入新值
//    while((li!=l.end())&&(*li!=24))
//    {
//        li++;
//
//    }
//    l.insert(li,72);
//    //对链表中的元素进行排序，//由小及大排序
//    l.sort();
//    cout << " " << endl;
//      for(li = l.begin();li != l.end();li++)
//    {
//        cout << *li << " ";
//    }
//    //关联容器 -- map：存储键值对，数据类型为pair<key,value>
//    map<string, int> m;     // 從 string 對應到 int
//    map<string,int>::iterator mi;
//    //插入元素:下标法和insert插入法
//    m["one"] = 1;       // "one" -> 1
//    m["two"] = 2;       // "two" -> 2
//    m["three"] = 3;     // "three" -> 3
//    m.insert(pair<string,int>("one",1));//pair<key,value>为键值对类型，假设定义p是pair类型p.first指的就是key,p.second值得是value
//    m.insert(pair<string,int>("two",2));
//    m.insert(map<string,int>::value_type("three",3));
//    m.insert(map<string,int>::value_type("four",4));
//    m.insert(map<string,int>::value_type("five",5));
//    m.insert(make_pair("six",6));
//    //访问元素
//    cout << m.count("four") << endl;//cout()返回m中k的出现次数
//    mi = m.find("two");
//    cout << (*mi).second << endl;//find()返回k索引元素的迭代器，否则返回末端迭代器
//    //迭代器遍历
//    for(mi = m.begin();mi != m.end();mi++)
//    {
//        cout << "key:" << mi->first << "  value:" << mi->second << endl;//迭代器->first获取元素的key值
//
//    }


}
