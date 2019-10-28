// 6_가상함수1
#include <iostream>
using namespace std;

class Animal
{
public:
	void Cry() { cout << "1" << endl; }
};
class Dog : public Animal
{
public:
	// 함수 오버라이드(override)
	void Cry() { cout << "2" << endl; }
};
int main()
{
	Animal a; a.Cry(); // 1
	Dog    d; d.Cry(); // 2

	Animal* p = &d;

	//if (사용자입력 == 1) p = &a;

	p->Cry();
}

// p->Cry() 를 어떤 함수로 연결할까 ? => 함수 바인딩

// 1. static binding : 컴파일 시간에 컴파일러가 함수를 결정
//					  무조건 포인터 타입으로 결정 => Animal Cry()
// early binding. 빠르다. 비논리적이다.
//						C++, C#

// 2. dynamic binding : 컴파일 시에 p가 가리키는 메모리 조사하는 기계어
//					코드 생성. 실행시 조사후 호출
//					Dog Cry()
// late binding. 느리다. 논리적이다.
//						java, swift, kotlin, objective-C
//						C++, C#의 virtual 함수.