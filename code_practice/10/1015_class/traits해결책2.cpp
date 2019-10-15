#include <iostream>
#include <type_traits>

using namespace std;

template<typename T> void foo(T a)
{
  // T의 포인터 여부에 따라 다른일 하기
  // if 문
  if( is_pointer<T>::value )
  {
    //....
    // 단, "*a = 10" 역참조 하는 코드를 사용할 수 없다.
    // 포인터 일때와 아닐때가 같은 함수에 있다보니
    // 컴파일 시, 오류가 발생함.
  }
  else
  {
    //...
  }
  // *a = 10를 사용하고 싶다면,
  // 1. if constexpr 사용 - 해결책 1.
  //
  // if constexpr( is_pointer<T>::value )
  // {
  //  *a = 10; ok..
  // }
  //
  // 2. true_tpye, false_type으로 오버로딩
  
  foo_imp(a, is_pointer<T>());
}

template<typename T> void foo_imp(T a, true_type){} // *a = 10 가능
template<typename T> void foo_imp(T a, false_type){}
