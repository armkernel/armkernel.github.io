// 7_SFINAE3
#include <iostream>
using namespace std;

void foo(...) { cout << "..." << endl; }

/*
template<typename T> void foo(T a) 
{
	typename T::type n;    // 1. SFINAE 규칙 적용	2. Error
						// 답은 Error
}
*/

// SFINAE 는 아래 3가지 경우만 사용가능

// 1. 함수 반환 타입 - 가장 널리 사용
template<typename T> typename T::type foo(T a) { return 0; }

// 2. 함수 인자 - 생성자등.. 반환타입이 없는 경우에 주로 사용
template<typename T> void foo(T a, typename T::type b = 0) { }


// 3. 템플릿 인자 - 함수 자체의 모양이 복잡하지 않은 장점이 있다.
template<typename T, typename T2 = typename T::type> void foo(T a) { }


int main()
{
	foo(10);
}





