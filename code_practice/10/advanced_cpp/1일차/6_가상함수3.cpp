#include <iostream>
using namespace std;

class A
{
	int a;
public:
	void foo() { cout << "1" << endl; }
};
class B			// ����.. A�� �ƹ� ���� ����.!!
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
			  // p->vtptr[1]() ��� ���� �ڵ� ����
}


// foo, goo ��� �񰡻��϶� : 2
// foo, goo ��� �����϶�   : 1
// foo ����, goo �񰡻�     : 2
// foo �񰡻�, goo����     :  runtime error

