#include <iostream>
using namespace std;

class Base
{
public:
	Base() { cout << "Base()"   << endl; }

	// �ٽ� 1. ��� Ŭ���� �Ҹ��ڴ� �����Լ��� ������ �Ѵ�.
	// 2. ��Ӱ��迡�� �Ҹ��ڴ� �̸��� �ٸ����� 
	//    ���� �̸� �Լ� �ΰ�ó�� �����Ѵ�.

	virtual ~Base() { cout << "~Base()" << endl; }
};
class Derived : public Base
{
public:
	Derived()  { cout << "Derived()" << endl; }
	virtual ~Derived() { cout << "~Derived()" << endl; }
};
int main()
{
	Base* p = new Derived;  // Derived ������ ȣ��. Base()
	delete p;
}



