// 4_move1
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// 복사 생성자 모양 1. call by value
	// 복사 생성자가 무한히 호출되는 표기법- 컴파일 에러
	//Point(Point pt) {} // Point pt = p2  => Point pt(p2)

	// 모양 2. call by reference
	// 사용가능. 에러 없음.
	// 단점. rvalue(임시객체)를 받을수 없다. 
	//       값을 반환하는 함수의 반환값을 받을수 없다.
	//Point(Point& pt) {}

	// 모양 3. call by const lvalue reference
	// lvalue 뿐 아니라 rvalue 모두 받을수 있다. 
	// 가장 좋은 표기법.
	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

Point foo()
{
	Point p;
	return p;
}
int main()
{
	Point p1;       // 디폴트 생성자
	Point p2(1, 2); // 인자 2개인 생성자
	Point p3(p2);   // Point( Point ) 의 생성자 필요

	Point ret = foo();// Point ret( foo() )
}



