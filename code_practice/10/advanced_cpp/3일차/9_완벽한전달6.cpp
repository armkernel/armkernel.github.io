// 9_완벽한전달3
#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}

// 결론
// 1. int&, int&& 로 2개 만들어야 한다.
// 2. int&& 버전에서는 다른 함수로 전달할때 rvalue 로 캐스팅해서 전달
/*
template<typename F> void chronometry(F f, int& arg)
{
	//f(arg);
	f( static_cast<int&>(arg) ); // 필요 없는 캐스팅..
								// 하지만 있어도 문제되지 않는다.
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/
// n(lvalue)  전달 => T : int&    T&& : int&
// 10(rvalue) 전달 => T : int     T&& : int&&
// 즉, 아래 템플릿은 2번째 인자가 n 인지 10 인지에 따라 위의 2개 함수생성
template<typename F, typename T> void chronometry(F f, T&& arg)
{
	// 질문 . 아래 캐스팅은 ?
	// 1. lvalue 캐스팅이다.
	// 2. rvalue 캐스팅이다.
	// 3. 2번째 인자가 무엇이냐에 따라 다른 캐스팅이다. (답)

	// 2번째 인자로 10(rvalue)를 보내면 _rvalue_ 로 캐스팅
	// 2번째 인자로 n(lvalue)를 보내면 _lvalue_ 로 캐스팅
	//f(static_cast<T&&>(arg));

	f( std::forward<T>(arg) ); // std::forward() 함수가 위처럼 캐스팅하고
							// 있습니다.
}




int main()
{
	hoo(10);

	chronometry(hoo, 10); 
}




