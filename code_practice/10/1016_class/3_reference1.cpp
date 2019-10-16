#include <iostream>

using namespace std;

int main()
{
  int n = 0;

  // 레퍼런스 규칙 ** 외워야함.
  // 1. non const lvalue reference 는 lvalue만 가리킨다.
  int& r1 = n; // ok
  int& r2 = 10; // error

  // 2. const lvalue reference 는 lvalue와 rvalue를 모두 가리킨다.
  //    단점: rvalue가 항상 const인 것은 아니다.
  //        즉, const화 시켜버림.
  const int& r3 = n; // ok
  const int& r4 = 10; // ok
  // const reference로는 가리킬 수 있음

  // 3. C++11. const 없이 rvalue 가리키는 참조가 필요함.
  // rvalue reference 는 rvalue만 가리킬 수 있다.
  // 언제 쓰나..? 
  int&& r5 = n; // error 둘 다 가리키는 건 이것 밖에 안됨.
  int&& r6 = 10; // ok
}

// C++ 도서
// ARM (Annoted Reference Manual)
