#include <iostream>
#include <type_traits>
using namespace std;

double hoo(short a, int b) { return 0; }

// traits를 잘못 사용할 때 처리 방법
// 1. typedef T type 제공하지 않는다.
// 2. static_assert() 사용해서 에러 메세지 출력
// 3. 선언자체만 한다. => 구현을 만들지 않는 방법
//    선언부가 없다면.. 부분특수화를 하지 못함.
//    의도적으로 primary template를 선언만 제공한다.

template<typename T> struct result_type
{
  // 
  // typedef T type;
  static_assert(is_function<T>::value, "error");
  // is_function c++표준 taits

};

template<typename R, typename ... Types>
struct result_type<R(Types...)>
{
  typedef R type;
};

template<typename T> void foo(const T& t)
{
  typename result_type<T>::type ret;
  cout << typeid(ret).name() << endl;
}


int main()
{
  // foo에 함수 타입을 보내야하는데.. int type을 보낸다면?? -. 케바케로 에러가 날 수도 있다.

  // 잘못 사용하면 에러를 호출하도록 한다.
  // 아예 typedef를 사용못하도록 함.
  int n = 0;
  foo(hoo);
}

// result type을 잘못 사용했을 때, 에러를 처리하는 방법에 대해 알아보자.


