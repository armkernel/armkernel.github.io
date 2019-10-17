// 1_캐스팅2.cpp
#include <iostream>
using namespace std;
// C++ 의 4개의 캐스팅
// static_cast  : 기본 캐스팅
//				1. 표준 타입을 값으로 캐스팅
//				2. void* => 다른 타입*
//              3. 관련성이 없는 타입의 주소는 캐스팅 안됨.
//					(하고 싶다면, reinterpret_cast)
//				4. rvalue => lvalue로 변경
// reinterpret_cast
// const_cast
// dynamic_cast
int main()
{
	double d = 3.4;
	//int    n = d; // ok
	int    n = static_cast<int>(d); // ok

	//int* p1 = malloc(100); // void* => int* 변환
							// C : ok, C++ : error

	int* p1 = static_cast<int*>(malloc(100)); // ok

	int* p2 = static_cast<int*>(&d); // double* => int*
									// error
	int&& r1 = n; // error
	int&& r1 = static_cast<int&&>(n); // ok..
					// 위 코드는 rvalue를 lvalue로 변경
					// 즉, 속성을 변경하는 캐스팅
	int&  r2 = static_cast<int&>(10);// error

}