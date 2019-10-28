#include <iostream>
// #include <type_traits>

using namespace std;

class Shape
{
  virtual void Draw() = 0;
};


template<typename U> struct xis_abstract
{
  typedef char YES[1];
  typedef char NO[2];

  template<typename T> static NO& check(T(*)[1]);
  template<typename T> static YES&  check(...);

  static constexpr bool value = (sizeof(check<U>(0)) == sizeof(int));
};

// 왜 check의 배열 포인터가 들어갔는가
// 왜 배열로 반환하는가
// allocator 
// sizeof => decltype 하는이유 
//
// cafe.naver.com/cppmaster

int main()
{
  cout << xis_abstract<Shape>::value << endl;
  /*
  if (sizeof(check<Shape>(0)) == sizeof(char))
    cout << " 추상아님 " << endl;
  else
    cout << " 추상 " << endl;
  */
}
