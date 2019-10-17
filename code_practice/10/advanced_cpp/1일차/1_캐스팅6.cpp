#include <iostream>
using namespace std;

// 값 캐스팅 : 임시객체를 만들게 된다.
// 참조 캐스팅 : 임시객체가 생성되지 않는다.
// "사용자 정의 타입에 대해서는 값 캐스팅을 사용하지 말자"


struct Base
{
	int value = 10;
	Base() { cout << "Base() : " << this << endl; }
	Base(const Base&) { cout << "복사생성자 : " << this << endl; }
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;
	cout << d.value << endl; // 20

	// 기반 클래스 멤버 접근하기.
	// 값 캐스팅 vs 참조 캐스팅
	cout << static_cast<Base>(d).value << endl; // 10
	//cout << static_cast<Base&>(d).value << endl;// 10

	// 임시객체는 등호의 왼쪽에 올수 없다.
	//static_cast<Base>(d).value = 30; // error
	//static_cast<Base&>(d).value = 30; // ok
}




