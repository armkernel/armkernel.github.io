// 1_checked_delete - 37 page
#include <iostream>
using namespace std;

class Point;  // 클래스 전방 선언(forward declaration)
			  // 완전한 선언이 있어도 포인터 변수는 만들수 있다
			// incomplete type
			// incomplete type 을 delete 하면 소멸자가 호출되지
			// 않는다.
void foo(Point* p)
{
	default_delete<int> d;

	// checked delete 라는 이름을 가진 기술
	//enum { type_must_be_complete = sizeof(Point) }; // incomplete type은 크기를 구할수 없다.
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
