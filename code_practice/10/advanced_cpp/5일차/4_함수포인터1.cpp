// 4_함수포인터1

#include <iostream>
using namespace std;

class Shape
{
public:
	void foo() { cout << "foo" << endl; }

	virtual void Draw() { cout << "shape" << endl; }
};
class Rect : public Shape
{
public:
	virtual void Draw() { cout << "rect" << endl; }
};
int main()
{
	void (Shape::*f1)() = &Shape::foo;

	void (Shape::*f2)() = &Shape::Draw; // f2에는 뭐가 있을까요 ?
				// 함수 주소가 아닌. 가상함수테이블에대한 index 정보

	Rect r;
	(r.*f2)(); 
	(((Shape&)r).*f2)();


}

