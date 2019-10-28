// 1_Temporary  
// github.com/webkit 
// webkit/source/wtf/wtf/scope.h 열어 보세요

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

// Temporary 의 활용
// 1. 함수 인자로만 사용할 객체라면 temporary 를 사용하는 것이 좋다
// 2. 함수가 temporary 를 받으려면 const 참조로 해야 한다.
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






