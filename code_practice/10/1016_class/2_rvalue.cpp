#include <iostream>

using namespace std;

int x = 0;
int foo() { return x; }
int& goo() { return x; }

// value 특징
// lvalue와 rvalue로 나뉨
//
// lvalue : 등호에 왼쪽에 올 수 있는 표기법 (오른쪽에도 올 수 있다.
//          lvalue to rvalue conversion)
//          값뿐 아니라 이름(메모리)을 가지고, 단일식을 넘어 존재
//          lvalue는 주소연산자를 사용해 주소를 구할 수 있음
//          참조를 반환하면 왼쪽에 올 수 있다.

// rvalue : 등호에 오른쪽에만 올 수 있다.
//          이름(메모리)이 없고, 단일식에서만 존재
//          주소연산자를 사용해 주소를 구할 수 없다.
//          값을 반환하는 함수.
//          "Temporary", 문자열을 제외한 literal

int main()
{
  int v1 = 10, v2 = 10;
  
  v1 = 20; // v1 : lvalue, 20 : rvalue
  10 = v1;  
  v2 = v1;

  int* p1 = &v1;
  int* p2 = &10;
  foo() = 10; // error
  goo() = 10; // ok

  const int c = 10;
  c = 20; // error. c는 lvalue, rvalue? => lvalue (값을 바꿀 수 없는 lvalue)
          // immutable lvalue라고 한다. 그냥 왼쪽에는 못오는데.. lvalue의 특징을 가짐

  // 다음 중 맞는 것은?
  char* s1 = "hello"; //error. 하지만 C 컴파일러는 허용, 예전 c++ 컴파일러 허용

  const char* s2 = "hello"; 
  // 문자열 char는 const char*이다.


  10; // rvalue

  "hello"; // 문자열 literal은 lvalue로 가는걸로 c++진영에서는 정함. 메모리가 잡힘

  "hello"[0] = 'a'; //  rvalue라서 에러나는게 아니라 const char[]라서 에러

}

