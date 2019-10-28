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

// 핵심 1. temporary 를 만드는 방법.
//      2. temporary 의 수명.

int main()
{
	//Point p(1, 1); // named object, 단일 문장을 넘어서 메모리에 존재
				   // 수명 : 객체를 생성한 블럭의 끝

	//Point(1, 1); // unnamed object, temporary  (object)
				 // 수명 : 문장의 끝(;)
				 // 단일 문장에서만 사용가능.

	Point(1, 1), cout << "X" << endl;

	cout << "----------" << endl;
}

