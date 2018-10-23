#include<boost/function.hpp>
#include<boost/bind.hpp>
#include<iostream>
typedef boost::function<int(int ,char)> Func;

int test(int num,char sign)
{
   std::cout<<num<<sign<<std::endl;
}

int main()
{
  Func f= boost::bind<test,2,'B'>;
  f=&test;  //or f=test
  f(1,'A');
}
