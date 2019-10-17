// 4_�������1
#include <iostream>
using namespace std;

class Car
{
	int speed;

	// mutable : ��� ��� �Լ� �ȿ����� ���� �����Ҽ� �ְ� �ϱ�
	//		     ���� ����� ���鶧
	mutable int m_count = 0;	// ��ü ������ ������ �������
public:
	// �ٽ� : ������� ���� �Լ��� �ݵ�� ������ �Լ��̾���Ѵ�.
	void ref()   const { ++m_count; }
	void deref() const { if (--m_count == 0) delete this; }

protected:
	~Car() { cout << "Car �ı�" << endl; }
};

int main()
{
	const Car* p1 = new Car;

	p1->ref();
	p1->deref();
}