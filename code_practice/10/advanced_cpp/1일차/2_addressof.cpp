// 2_addressof1.cpp
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point* operator&() const
	{
		return nullptr; // C++11 ���ʹ� 0��� nullptr ���
	}
};
int main()
{
	Point pt;
	cout << &pt << endl; // pt.operator&()

	// pt�� �ּҸ� ���� ���ô�.
	Point* p1 = &pt; // ���� .. 0

	// step1. char* Ÿ�Կ� ��� ����
	//char* p2 = reinterpret_cast<char*>(&pt); // &pt�̹Ƿ�
								// operator& ȣ��.  0. ����

	//char* p2 = &reinterpret_cast<char>(pt);
				// ������ 1. reinterpret_cast�� �� ĳ���� �ȵ�
				//       2. �� ĳ������ �ӽð�ü�� ����Եȴ�.
	char* p2 = &reinterpret_cast<char&>(pt); // ok..
	

	// step 2. Point Ÿ�Կ� ���

	Point* p3 = reinterpret_cast<Point*>(
					&reinterpret_cast<char&>(pt)); 

	cout << p3 << endl; // ok.
}



