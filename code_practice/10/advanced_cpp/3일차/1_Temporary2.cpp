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

// Temporary 의 특징

int main()
{
	Point p(0, 0);
	p.x = 10;  // ok

	//Point(0, 0).x = 10; // 특징 1. temporary 는 lvalue가
						// 될수 없다.(등호에 왼쪽에 올수 없다.)
						// 질문 : temporary 는 상수 일까요 ?
						//		상수는 아닙니다.
	Point(0, 0).set(10, 20); // ok


	Point* p1 = &p;
	//Point* p2 = &Point(0,0); // error. Temporary 는 & 연산자를 사용해서
							// 주소를 구할수 없다.


	// 특징 3. 
	Point& r1 = p; // ok

//	Point& r2 = Point(0, 0); // error. temporary를 참조 할수없다

	const Point& r3 = Point(0, 0); // ok.. const 참조는
									// temporary를 가리킬수 있다
					// temporary 의 수명이 r3의 수명으로 연장됩니다.
					// "temporary materialization" 이라는 개념

	// 위코드의 문제점 : temporary는 상수가 아닌데.
	//				    상수 참조로만 가리킬수 있다.
	// C++11 비상수 참조로 가리킬수 없을까 ?
	Point&& r4 = Point(0, 0); // ok
	r4.x = 10;

}






