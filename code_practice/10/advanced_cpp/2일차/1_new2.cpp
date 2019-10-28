#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b)
	{
		cout << "Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
};
int main()
{
	// Point 객체를 힙에 한개 만들기
	Point* p1 = new Point(0, 0);

	// 힙에 10개 만들어 보세요!!
	//Point* p2 = new Point[10]; // error.

	// 디폴트 생성자가 없는 객체를 여러개 생성하려면 
	// 메모리 할당과 생성자 호출을 분리하면 됩니다.
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	// 10개의 메모리 공간에 생성자 호출
	for (int i = 0; i < 10; i++)
		new(&p2[i]) Point(0, 0);

	//delete [] p2;  // 이렇게 하지말고.. 아래 처럼 분리하세요

	// 사용후에는 소멸자 호출
	for (int i = 0; i < 10; i++)
		p2[i].~Point();

	// 메모리 해지.
	operator delete(p2);
}






