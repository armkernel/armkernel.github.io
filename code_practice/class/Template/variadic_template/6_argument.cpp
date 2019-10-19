#include <iostream>
// 함수의 인자를 구하는 trait를 만들어보자
//
using namespace std;
template<size_t N, typename T> struct argument_type
{
  typedef T type;
};

template<size_t N, typename R, typename A1, typename A2> struct argument_type<N, R(A1,A2)>
{
  typedef T type;
};

double hoo(short a, int b) { return 0; }

template<typename T> void foo( const T& t )
{
  // T: double (short, int)
  typename argument_type<0, T>::type ret;

  cout << typeid(ret).name() << endl;
}

int main()
{
  foo(hoo);
}

// 함수의 정보 구하는 trait 만들기
// 1. primary template을 만들고 "typedef T type" 제공
// 2. 함수 타입 T안에 있는 함수 인자 타입을 얻을 수 있도록 부분 특수화 한다.
//  T -> R(A1, A2), => T -> R(A1, Types...)
