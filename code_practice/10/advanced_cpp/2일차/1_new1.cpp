// github.com/aosp-mirror
// platform_system_core  - 2��° page�� �ֽ��ϴ�.
// libutils/include/utils/typehelpers.h
// "copy_type" �Լ� 2��
// 1_new1.cpp  - 103 page ~
//               104 page�߰��� construct() �Լ����� 

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) 
	{
		cout << "Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl;	}
};
int main()
{
	// 1. �޸� �Ҵ�
	// 2. ������ ȣ��
	//Point* p1 = new Point(1, 2);

	// 1. �Ҹ��� ȣ��
	// 2. �޸� ����
	//delete p1;

	// �޸� �Ҵ�� ������ ȣ���� �и�
	// 1. �޸𸮸� �Ҵ� ( C �� malloc �� ����)
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point)));
	cout << p2 << endl;

	// 2. �Ҵ�� �޸𸮿� ������ ȣ�� - Placement new ��� ���
	// new Point(1, 2);    // �޸��Ҵ� + ������ ȣ��
	new(p2) Point(1, 2);// �̹������ϴ� �޸�(p2)�� ������ ȣ��  

	//p2->Point(1, 2); // �̷��� �Ǹ� ������ ������.. error

	// 3. �Ҹ��ڸ� ȣ��
	p2->~Point(); // �޸� ���� ���� �Ҹ��� ȣ��


	// 4. �Ҹ��� ȣ����� �޸𸮸� ����
	//delete p2; // �Ҹ��� ȣ�� + �޸� ����
	operator delete(p2); // �޸𸮸� ����
}


