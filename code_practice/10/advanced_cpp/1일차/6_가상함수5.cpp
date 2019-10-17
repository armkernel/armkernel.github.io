#include <iostream>
using namespace std;

class Base
{
public:
	Base() { cout << "Base()"   << endl; }

	// 핵심 1. 기반 클래스 소멸자는 가상함수로 만들어야 한다.
	// 2. 상속관계에서 소멸자는 이름이 다르지만 
	//    동일 이름 함수 인것처럼 동작한다.

	virtual ~Base() { cout << "~Base()" << endl; }
};
class Derived : public Base
{
public:
	Derived()  { cout << "Derived()" << endl; }
	virtual ~Derived() { cout << "~Derived()" << endl; }
};
int main()
{
	Base* p = new Derived;  // Derived 생성자 호출. Base()
	delete p;
}



