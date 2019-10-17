#include <iostream>
using namespace std;

class A
{
	int a;
public:
	void foo() { cout << "1" << endl; }
};
class B			// 주의.. A와 아무 관계 없음.!!
{
	int b;
public:
	virtual void goo() { cout << "2" << endl; }
};
int main()
{
	A aaa;
	B* p = reinterpret_cast<B*>(&aaa);

	p->goo(); // 1 ? 2				goo(p)
			  // p->vtptr[1]() 라는 기계어 코드 생성
}


// foo, goo 모두 비가상일때 : 2
// foo, goo 모두 가상일때   : 1
// foo 가상, goo 비가상     : 2
// foo 비가상, goo가상     :  runtime error

