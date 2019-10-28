#include <iostream>
#include <type_traits>

using namespace std;

template<typename T> void foo(T a)
{
  // type traits 기술의 종류
  // 1. 타입 질의
  bool b = is_pointer<T>::value;
  bool b1 = is_pointer_v<T>; // 이걸 많이 씀

  // 2. 변형된 타입 얻기
  typename remove_pointer<T>::type n; // type을 꺼내기 때문에 type..
  remove_pointer_t<T> n2; // typename 생략가능. <- 훨씬 더 간결 하다.
}

int main()
{

}
