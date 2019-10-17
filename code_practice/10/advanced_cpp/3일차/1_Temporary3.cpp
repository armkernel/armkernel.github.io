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

// Temporary �� Ȱ��
// 1. �Լ� ���ڷθ� ����� ��ü��� temporary �� ����ϴ� ���� ����
// 2. �Լ��� temporary �� �������� const ������ �ؾ� �Ѵ�.
void foo( const Point& p) 
{
}

int main()
{
//	Point p(0, 0);
//	foo(p);

	foo( Point(0, 0) );

	cout << "-----" << endl;
}






