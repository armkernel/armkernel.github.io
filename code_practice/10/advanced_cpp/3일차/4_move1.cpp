// 4_move1
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// ���� ������ ��� 1. call by value
	// ���� �����ڰ� ������ ȣ��Ǵ� ǥ���- ������ ����
	//Point(Point pt) {} // Point pt = p2  => Point pt(p2)

	// ��� 2. call by reference
	// ��밡��. ���� ����.
	// ����. rvalue(�ӽð�ü)�� ������ ����. 
	//       ���� ��ȯ�ϴ� �Լ��� ��ȯ���� ������ ����.
	//Point(Point& pt) {}

	// ��� 3. call by const lvalue reference
	// lvalue �� �ƴ϶� rvalue ��� ������ �ִ�. 
	// ���� ���� ǥ���.
	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

Point foo()
{
	Point p;
	return p;
}
int main()
{
	Point p1;       // ����Ʈ ������
	Point p2(1, 2); // ���� 2���� ������
	Point p3(p2);   // Point( Point ) �� ������ �ʿ�

	Point ret = foo();// Point ret( foo() )
}



