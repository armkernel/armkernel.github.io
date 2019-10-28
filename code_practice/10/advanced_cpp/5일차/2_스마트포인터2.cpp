// 2_스마트포인터2
#include <iostream>
using namespace std;

class Car
{
public:
	void Go() { cout << "Car Go" << endl; }
	~Car()    { cout << "~Car" << endl; }
};
// 아래 코드가 핵심입니다.
// 개념 : 임의의 객체가 다른 타입의 포인터 역활을 하는 것
// 원리 : -> 와 * 를 재정의 해서 포인터 처럼 보이게 한다.

// 장점 : raw pointer 가 아닌 객체이다.
//        생성/복사/대입/소멸의 과정에 추가의 작업을 할수 있다.
//        대표적 활용이 소멸자에서 자동 삭제 기능.
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}

	~Ptr() { delete obj; }
	Car* operator->() { return obj; }
	Car& operator*() { return *obj; }  // 핵심.. 반드시 참조 리턴해야합니다.
};

int main()
{
	Ptr p = new Car; // Ptr p( new Car )

	p->Go(); // (p.operator->())Go() 라는 모양이지만
			 // (p.operator->())->Go() 처럼 해석해 줍니다.
	(*p).Go();// p.operator*()
}