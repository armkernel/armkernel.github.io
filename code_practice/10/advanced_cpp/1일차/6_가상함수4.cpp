#include <iostream>
using namespace std;

class A
{
public:
	virtual void foo(int n = 10) { cout << "A " << n << endl; }
};
class B : public A			
{
public:
	virtual void foo(int n = 20) { cout << "B " << n << endl; }
};
int main()
{
	A* p = new B;
	p->foo(); // ��� ������ ������.
			  // B 10
		// p->vtptr[1](10) ��� ���� �ڵ� ����

	// ����Ʈ �Ķ���� : ������ �ð��� ä���.
	// �����Լ� ȣ��   : ����ð��� ����

	// ��� : �����Լ����� ����Ʈ �Ķ���� ������ ������� ������.

}



