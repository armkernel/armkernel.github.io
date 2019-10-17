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

// Temporary �� �Լ� ��ȯ Ÿ��

// 1. �Լ� ����
//void foo(Point pt) {} // call by value : ���纻 ��ü�� ����
void foo(Point& pt) {} // call by reference : ���纻 ���� �ȵ�.

// 2. �Լ� ��ȯ Ÿ��
Point pt(0, 0);
Point goo() { return pt; } //�� ���� : pt �� ������ temporary��ȯ 
Point& hoo() { return pt; } // ���� ��ȯ : ���纻�� �ƴ� pt��ȯ

Point& koo()
{
	Point p(0, 0);
	return p; // ����... ���� ���������� ������ ��ȯ�ϸ� �ȵ�.
}

int main()
{
	Point p;
	foo(p);

	//goo().x = 10; // error. �ӽð�ü�� lvalue�� �ɼ� ����.
	hoo().x = 10; // ok..


}






