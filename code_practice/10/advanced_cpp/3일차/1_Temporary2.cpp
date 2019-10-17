// 1_Temporary  
// github.com/webkit 
// webkit/source/wtf/wtf/scope.h ���� ������

#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b)
	{
		cout << "Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }

	void set(int a, int b) { x = a; y = b; }
};

// Temporary �� Ư¡

int main()
{
	Point p(0, 0);
	p.x = 10;  // ok

	//Point(0, 0).x = 10; // Ư¡ 1. temporary �� lvalue��
						// �ɼ� ����.(��ȣ�� ���ʿ� �ü� ����.)
						// ���� : temporary �� ��� �ϱ�� ?
						//		����� �ƴմϴ�.
	Point(0, 0).set(10, 20); // ok


	Point* p1 = &p;
	//Point* p2 = &Point(0,0); // error. Temporary �� & �����ڸ� ����ؼ�
							// �ּҸ� ���Ҽ� ����.


	// Ư¡ 3. 
	Point& r1 = p; // ok

//	Point& r2 = Point(0, 0); // error. temporary�� ���� �Ҽ�����

	const Point& r3 = Point(0, 0); // ok.. const ������
									// temporary�� ����ų�� �ִ�
					// temporary �� ������ r3�� �������� ����˴ϴ�.
					// "temporary materialization" �̶�� ����

	// ���ڵ��� ������ : temporary�� ����� �ƴѵ�.
	//				    ��� �����θ� ����ų�� �ִ�.
	// C++11 ���� ������ ����ų�� ������ ?
	Point&& r4 = Point(0, 0); // ok
	r4.x = 10;

}






