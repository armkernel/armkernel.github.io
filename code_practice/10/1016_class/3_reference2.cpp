#include <iostream>

using namespace std;

// __FUNCTION__ : 함수 이름. C++표준 -> 이름만 나옴.. 이름에 인자, 반환값 보려면 아래 것.
// __FUNCSIG__ : 함수이름 + signature, vc++ 에서만 사용 가능
//                g++ : __PRETTY_FUNCTION__
void foo(int& a)  { cout << __PRETTY_FUNCTION__ << endl; }
void foo(const int& a)  { cout << __PRETTY_FUNCTION__ << endl; }
void foo(int&& a)  { cout << __PRETTY_FUNCTION__ << endl; }

int main()
{
  int n = 10;
  foo(n); // const였다면 const로 감. 1,2번 고민할 수 있음. 없으면 2번으로 감.
  foo(10); // 2,3 으로 갈 수 있음.. 없으면 2번으로 감.

  int& r1 = n;
  foo(r1); // 1번 호출, 없으면 2번

  // rvalue reference type이 맞는데.. 속성은 lvalue

  int&& r2 = 10; // 이름 없음.. 
                 // 이름 있게 쓸 수 있다.
                 // r2 <- lvalue.. "중요!"
                 // rvalue, lvalue 식에 대한 속성 
  foo(r2); // 1번 호출 없으면 2번
  foo(r2 + 1 ); // 3번 호출 없으면 2번

  // int& , int && : 데이터 타입
  // rvalue, lvalue : 표현식에 대한 속성 
  //
  // r2가 3번을 호출 되게 하려면 lvalue-> rvalue로 속성 변경 필요
  foo(static_cast<int&&>(r2)); // 3번
  // 같은 타입으로 바꿈.. 캐스팅의 효과가 없는 것 아닌가?
  // 데이터 타입을 바꾸는 것이 아니라 데이터 속성을 변경하도록 함.
  // static_cast 데이터 타입 표현식? 예외적으로 && 표기법이 들어오면
  // value를 바꾸는 표현식이다. value속성을 바꾸는 표현식이라고 명시적으로 문서에 나와있음
  // 거꾸로 하는 건 에러.

  foo(static_cast<int&>(10)); // error.
}
