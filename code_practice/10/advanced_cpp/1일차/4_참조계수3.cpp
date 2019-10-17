// 4_참조계수1
#include <iostream>
using namespace std;

class Car
{
	int speed;

	// mutable : 상수 멤버 함수 안에서도 값을 변경할수 있게 하기
	//		     위한 멤버를 만들때
	mutable int m_count = 0;	// 객체 수명을 관리할 참조계수
public:
	// 핵심 : 참조계수 조작 함수는 반드시 상수멤버 함수이어야한다.
	void ref()   const { ++m_count; }
	void deref() const { if (--m_count == 0) delete this; }

protected:
	~Car() { cout << "Car 파괴" << endl; }
};

int main()
{
	const Car* p1 = new Car;

	p1->ref();
	p1->deref();
}