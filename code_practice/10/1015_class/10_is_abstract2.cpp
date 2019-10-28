#include <iostream>
// #include <type_traits>

using namespace std;

class Shape
{
  virtual void Draw = 0;
};

// 1. 조건을 만족하는 경우만 만족하지 않는 경우에 다른 함수가 호출되도록한다>?
//

// 2. 확인만 하면 된다. 따라서, 구현부는 만들 필요 없다.
//    "평가되지 않는 표현식"
template<typename T> char check(T(*)[1]);
template<typename T> int  check(...);

int main()
{
  //Shape s;
  // 추상클래스를 보내지 못함.
  check<Shape>(0);
  // 추상클래스는 객체는 못만들지만 포인터는 만들 수 있다.
  // 배열을 가리키는 포인터는 만들 수 없다.
  //check(s);
  


  if (sizeof(check<Shape>(0)) == sizeof(char))
    cout << " 추상아님 " << endl;
  else
    cout << " 추상 " << endl;
}
