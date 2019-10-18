#include <iostream>

using namespace std;

// 이런걸 가변인자 템플릿이라고 한다.
// T안에는 두개가 들어있다.
// 코딩 관례상 복수로 표현한다. => Types..
// Types => int,char 이런식으로 들어있다.
// 꺼내는게 중요하다.
// template<typename T> class xtuple
template<typename ... T> class xtuple
{
};

// 클래스 템플릿 뿐만아니라 함수의 템플릿도
// 가변인자로 만들 수 있다.
template<typename ... Types>
void foo(Types ... args)
{
  // 이자리의 인자 갯수는 다양하게 쓸 수 있다.
  // 하나만 보내도 되고 다양한타입으로 보내면 된다.
  // ... 의 위치는 햇갈린다.
  // 모양을 정확히 기억하는게 중요해.
}


int main()
{
  xtuple<> t0; // 아무것도 안보내도 문제없다.

  xtuple<int> t1;
  // template인자를 하나만 보내야해
  //
  foo();
  foo(1);
  foo(1, 3.4, "A");
  // 어쩔 때는 하나 두개 세개 이렇게 보내고 싶을때가 있다.
  xtuple<int,char> t2;
}


// 가변인자 템플릿
// 1. C++11 부터 지원된다.
// 2. 가변인자 템플릿( 클래스 템플릿, 함수 템플릿)의 기본 모양
// 3. 가변인자 템플릿의 템플릿 인자인 "Types"는 여러개의 타입을 나타낸다.
// 4. 가변인자 함수 템플릿의 함수 인자인 args 안에는 여러개의 값이 들어있다.
//  => 여러개의 값이 들어있는 것을 "Parameter Pack"
//  Parameter들이 여러개가 들어있다는 내용

