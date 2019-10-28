#include <iostream>
using namespace std;

// �� ĳ���� : �ӽð�ü�� ����� �ȴ�.
// ���� ĳ���� : �ӽð�ü�� �������� �ʴ´�.
// "����� ���� Ÿ�Կ� ���ؼ��� �� ĳ������ ������� ����"


struct Base
{
	int value = 10;
	Base() { cout << "Base() : " << this << endl; }
	Base(const Base&) { cout << "��������� : " << this << endl; }
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;
	cout << d.value << endl; // 20

	// ��� Ŭ���� ��� �����ϱ�.
	// �� ĳ���� vs ���� ĳ����
	cout << static_cast<Base>(d).value << endl; // 10
	//cout << static_cast<Base&>(d).value << endl;// 10

	// �ӽð�ü�� ��ȣ�� ���ʿ� �ü� ����.
	//static_cast<Base>(d).value = 30; // error
	//static_cast<Base&>(d).value = 30; // ok
}




