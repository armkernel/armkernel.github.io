#include <iostream>
using namespace std;

// __FUNCTION__ : 함수이름. C++ 표준
// __FUNCSIG__  : 함수이름 + signature, VC++ 에서만 가능
//                 g++ : __PRETTY_FUNCTION__ 사용

void foo(int& a)       { cout << __FUNCSIG__ << endl; }
void foo(const int& a) { cout << __FUNCSIG__ << endl; }
void foo(int&& a)      { cout << __FUNCSIG__ << endl; }

int main()
{
	int n = 10;
	foo(n);		// 1번 호출, 없으면 2번
	foo(10);	// 3번 호출, 없으면 2번

	int& r1 = n;
	foo(r1);	// 1번 호출, 없으면 2번

	int&& r2 = 10;	// 10은 rvalue 이지만 r2는 lvalue 입니다. "중요!!"
	foo(r2);	// 1번 호출, 없으면 2번
	foo(r2+1);  // 3번 호출, 없으면 2번

	// r2가 3번을 호출되게 하려면 lvalue => rvalue로 속성 변경 필요
	foo(static_cast<int&&>(r2)); // 3번

//	foo(static_cast<int&>(10)); // 1번이 될까..?? error

	
	// int&, int&& : 데이타 타입
	// rvalue, lvalue : 표현식에 대한 속성.!!
}


