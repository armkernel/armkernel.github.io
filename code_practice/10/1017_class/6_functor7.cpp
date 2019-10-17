#include <iostream>
#include <algorithm>
#include <functional> // less<>, greater<> 여기에 있다.

using namespace std;

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

// 아래 둘은 기계어 코드가 없다. 치환됨
struct less
{
  inline bool operator()(int a, b) { return a < b; }
};
struct greater
{
  inline bool operator()(int a, b) { return a > b; }
};

template<typename T> void foo(T f)
{
  bool b = f(1,2);
}

int main()
{
  Less f1;
  Greater f2;

  foo(cmp1); // T : bool(*)(int,int)
  foo(cmp2); // T : bool(*)(int,int)
  foo(f1);   // T : Less
  foo(f2);   // T : Greater
}

// 1. 컴파일 하면 foo함수는 몇 개가 생성될까요? 3
// 2. foo 제외하고 함수가 몇개 더 있을 까요? 3
