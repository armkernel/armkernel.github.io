#include <iostream>
using namespace std;

double hoo(short a, int b) { return 0; }

template<typename T> struct result_type
{
  typedef T type;
};

template<typename R, typename ... Types>
struct result_type<R(Types...)>
// 함수의 인자의 갯수가 있어도 없어도 되고
// 다양하게 전달하도록 해라
{
  typedef R type;
};

// 위와 같이 만들면,, 문제점..-> 함수 인자 2개만 받는 것에 대해 처리할 수 있다.
// 함수의 인자의 갯수는 다양하다. 좀 더 유연하게 바꿀 필요가 있다.
//

template<typename T> void foo(const T& t)
{
  // hoo 를 호출하니.. T의 모양은 double (short, int)인 함수 모양.

  typename result_type<T>::type ret;

  cout << typeid(ret).name() << endl;
}


int main()
{
  foo(hoo);
}

// 함수의 정보를 구하는 traits 만들기
// 규칙이 있음
// 1. primary template을 만들고 "typedef T type"을 제공한다.
//
// 2. 함수 타입인 T안에 있는 return 타입을 얻을 수 있도록 부분 특수화
//  - T -> R(A1,A2)
//
//  3. 인자 갯수에 제한을 없애기 위해서 가변인자 템플릿 사용
//    - T -> R(Types...)
