// 1_checked_delete - 37 page
#include <iostream>
using namespace std;

class Point;  // Ŭ���� ���� ����(forward declaration)
			  // ������ ������ �־ ������ ������ ����� �ִ�
			// incomplete type
			// incomplete type �� delete �ϸ� �Ҹ��ڰ� ȣ�����
			// �ʴ´�.
void foo(Point* p)
{
	default_delete<int> d;

	// checked delete ��� �̸��� ���� ���
	//enum { type_must_be_complete = sizeof(Point) }; // incomplete type�� ũ�⸦ ���Ҽ� ����.
	static_assert(sizeof(Point) > 0, "type is incomplete");

	delete p;	
}



class Point
{
	int x, y;
public:
	Point()  { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
	Point* p1 = new Point;
	foo(p1);
}
