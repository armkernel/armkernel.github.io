#include <iostream>
#include <algorithm>
#include <functional> 
using namespace std;

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less    {inline bool operator()(int a, int b) { return a < b; }};
struct Greater {inline bool operator()(int a, int b) { return a > b; } };

template<typename T> void foo(T f)
{
	bool b = f(1, 2);
}
int main()
{
	Less f1;
	Greater f2;
	foo(cmp1); // T : bool(*)(int, int)
	foo(cmp2); // T : bool(*)(int, int)
	foo(f1);   // T : Less
	foo(f2);   // T : Greater
}
// 1. 컴파일 하면 foo 함수는 몇개가 생성될까요 ? => 3개 생성
// 2. foo 를 제외하고 함수가 몇개 더 있을까요 ?



// cl 6_함수객체7.cpp  /FAs   /Ob1
// g++			  -S      -O2

// notepad 6_함수객체7.asm   으로 열어 보세요


// /Ob1 : 인라인 치환을 적용하라는 옵션
// /FAs : 어셈블리 소스를 만들어 달라는 옵션