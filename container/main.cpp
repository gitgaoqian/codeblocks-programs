#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class B;
class A
{
public:
 A(  ) : m_sptrB(nullptr) { };
 ~A( )
 {
  cout<<" A is destroyed"<<endl;
 }
 shared_ptr<B> m_sptrB;
};
class B
{
public:
 B(  ) : m_sptrA(nullptr) { };
 ~B( )
 {
  cout<<" B is destroyed"<<endl;
 }
 shared_ptr<A> m_sptrA;
};
//***********************************************************
int main( )
{
 shared_ptr<B> sptrB( new B );
 shared_ptr<A> sptrA( new A );
 shared_ptr<A> sptrC(sptrA);
 weak_ptr<A> sptrD(sptrA);
 cout << sptrA.use_count() << endl;
  cout << sptrC.use_count() << endl;
 sptrB->m_sptrA = sptrA;
 sptrA->m_sptrB = sptrB;
 cout << sptrA << endl;
 cout << sptrB << endl;
 cout << sptrC << endl;
 cout << sptrD.lock()->m_sptrB << endl;
 cout << sptrA.use_count() << endl;
}
