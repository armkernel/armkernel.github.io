// 5_move구현1
#include <iostream>
#include <string>
using namespace std;

// rule of 3
// 포인터가 있고 생성자에서 자원 할당하면
// "소멸자, 복사 생성자, 대입연산자"가 필요하다.

// 이 소스의 핵심 - 복사생성자, 대입연산자 만드는 방법.

class People 
{
	string name;
	int    age;
	char*  addr;
public:
	People(string n, int a, const char* ad) : name(n), age(a)
	{
		addr = new char[strlen(ad) + 1];
		strcpy(addr, ad);
	}
	~People() { delete[] addr; }

	// 복사 생성자
	People(const People& p) : name(p.name), age(p.age)
	{
		// 포인터가 아닌 멤버는 그냥 복사해도 되지만
		// 포인터는 메모리를 복사(또는 참조계수)
		addr = new char[strlen(p.addr) + 1];
		strcpy(addr, p.addr);
	}

	// 복사 생성자를 만든 경우는 대부분 대입연산자도 필요 하다.
	// 규칙 1.  반환값은 자신을 참조로 해야 한다.
	//     2.   자신과의 대입을 조사해야 한다.
	//    3.  기반 클래스가 있다면 기반 클래스의 대입연산자도 호출한다.
	//    4.  예외에 안전하게 작성해야 한다. - 교재 - copy and swap 항목
	People& operator=(const People& p)
	{
		// 자신과의 대입 조사
		if (&p == this) return *this;

		// 기반 클래스가 있다면 기반 클래스의 대입연산자도 호출해야 한다.
		//Base::operator=(p);


		// 포인터가 아니면 그냥 대입
		name = p.name;
		age = p.age;

		// 포인터는 기존 메모리를 제거하고, 새로운 메모리에 복사
		delete[] addr;
		addr = new char[strlen(p.addr) + 1];
		strcpy(addr, p.addr);
		return *this;
	}
};
int main()
{
	People p1("kim", 10, "seoul");
	p1 = p1;

	People p2 = p1; // 복사 생성자
	p2 = p1;		// p2.operator=(p1).  대입연산자


	int n = 10;

	n = n;

	(n = 20) = 30; // ???
}
