// 4_참조계수1
#include <iostream>
using namespace std;

class Car
{
	int speed;
	int m_count = 0;	// 객체 수명을 관리할 참조계수
public:
	void ref()   { ++m_count; }
	void deref() { if (--m_count == 0) delete this; }

	// protected 소멸자 : 객체를 stack 에 만들수 없게 한다. 195 page
protected:
	~Car() { cout << "Car 파괴" << endl; }
};
int main()
{
	//Car c; // 위 처럼 디자인 했다면 stack 객체를 만들수 없게 하는 것이
			// 좋다 - 교재 195 page.. onlyHeap 클래스.


	Car* p1 = new Car;
	p1->ref();			// 규칙 1. 객체 생성시 참조계수 증가
	Car* p2 = p1;		
	p2->ref();			// 규칙 2. 객체 주소 복사시 참조계수 증가

	p2->deref();	// 규칙 3. 사용후 참조계수 감소.
	p1->deref();
}