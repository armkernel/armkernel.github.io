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

// Temporary 와 함수 반환 타입

// 1. 함수 인자
//void foo(Point pt) {} // call by value : 복사본 객체를 생성
void foo(Point& pt) {} // call by reference : 복사본 생성 안됨.

// 2. 함수 반환 타입
Point pt(0, 0);
Point goo() { return pt; } //값 리턴 : pt 를 복사한 temporary반환 
Point& hoo() { return pt; } // 참조 반환 : 복사본이 아닌 pt반환

Point& koo()
{
	Point p(0, 0);
	return p; // 버그... 절대 지역변수의 참조를 반환하면 안됨.
}

int main()
{
	Point p;
	foo(p);

	//goo().x = 10; // error. 임시객체는 lvalue가 될수 없다.
	hoo().x = 10; // ok..


}






