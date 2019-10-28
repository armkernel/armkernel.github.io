#include <iostream>
using namespace std;


class Test
{
public:
	void hoo(int a) { cout << "Test::hoo" << endl; }
};


void goo(int a, int b) { cout << "goo" << endl; }


template<typename T, typename ... ARGS> 
void foo(T&& f, ARGS&& ... args )
{
	//f( std::forward<ARGS>(args)...);
	invoke( std::forward<T>(f) , std::forward<ARGS>(args)...);
}

int main()
{
	foo(goo, 1, 2);

	Test test2;
	foo(&Test::hoo, &test2, 10); // ok..



	// 멤버 함수 포인터 만드는 방법
	void(Test::*f)(int) = &Test::hoo; // 핵심 1. 

	//f(10); // error. 객체가 없다.

	Test test;
	//test.f(10); // error. f라는 멤버 함수가 없다.

	//test.*f(10); // .* 연산자 (pointer to member )
				// 우선순위 문제로 error

	(test.*f)(10); // 핵심 2. 멤버 함수 포인터로 함수 호출하는 코드

	// 위 코드가 좋으세요 ? 아래 코드가 좋으세요 ?
	//f(&test, 10); // 보기 좋다.. 하지만 에러..

	// 그래서 invoke 를 만들 었다. c++17
	invoke(f, &test, 10);
}



