// 4_�������1
#include <iostream>
using namespace std;

class Car
{
	int speed;
	int m_count = 0;	// ��ü ������ ������ �������
public:
	void ref()   { ++m_count; }
	void deref() { if (--m_count == 0) delete this; }

	// protected �Ҹ��� : ��ü�� stack �� ����� ���� �Ѵ�. 195 page
protected:
	~Car() { cout << "Car �ı�" << endl; }
};
int main()
{
	//Car c; // �� ó�� ������ �ߴٸ� stack ��ü�� ����� ���� �ϴ� ����
			// ���� - ���� 195 page.. onlyHeap Ŭ����.


	Car* p1 = new Car;
	p1->ref();			// ��Ģ 1. ��ü ������ ������� ����
	Car* p2 = p1;		
	p2->ref();			// ��Ģ 2. ��ü �ּ� ����� ������� ����

	p2->deref();	// ��Ģ 3. ����� ������� ����.
	p1->deref();
}