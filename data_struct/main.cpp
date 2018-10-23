//利用c++的库文件的数据结构操作:https://blog.csdn.net/livecoldsun/article/details/25011413
#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;

int main()
{
// 栈操作:
//s.push(item);		//将item压入栈顶
//s.pop();			//删除栈顶的元素，但不会返回
//s.top();			//返回栈顶的元素，但不会删除
//s.size();			//返回栈中元素的个数
//s.empty();			//检查栈是否为空，如果为空返回true，否则返回false

	stack<int> s;
	int snum;
	int i=0;
	cout<<"------Test for Stack-------"<<endl;
	cout<<"Input number:"<<endl;

	while(i<6)
	{
        cin>>snum;
		s.push(snum);
		i++;
	}

	cout<<"The Stack has "<<s.size()<<" numbers.They are:"<<endl;
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<"\nNow the size is "<<s.size()<<endl;
//队列操作
//q.push(item)           //将item插入队尾
//q.pop()                //删除队首元素，但不返回
//q.front()              //返回队首元素，但不删除
//q.back()               //返回队尾元素，但不删除
//q.size()               //返回队列中元素的个数
//q.empty()              //检查队列是否为空，如果为空返回true，否则返回false

    queue<int> q;
	int qnum;
    int j=0;
	cout<<"------Test for Queue-------"<<endl;
	cout<<"Input number:"<<endl;
	while(j<6)
	{
        cin>>qnum;
		q.push(qnum);
		j++;
	}
	cout<<"Now the Queue has "<<q.size()<<" numbers."<<endl;
	cout<<"The first is "<<q.front()<<endl;
	cout<<"The last is "<<q.back()<<endl;
	cout<<"All numbers："<<endl;
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<"Now the Queue has "<<q.size()<<" numbers."<<endl;

}
