#include <iostream>

using namespace std;

class Point
{
public:
  Point(int a, int b) {}
  Point(const Point& p) { cout << "copy" << endl; }
  Point(Point&& p) { cout << "move" << endl; }
};

// 템플릿을 만들 때, 인자를 T&로 할 것인가? T&& 할것인가?
// T& : lvalue 만 받겠다.
// T&& : lvalue 와 rvalue 모두 받겠다. 
/* forward를 만든거임.
template<typename T> T&& xmove(T&& arg)
{
  // xmove(lvalue) : T 는 int&
  // xmove(rvalue) : T 는 int
  // 즉, 아래 캐스팅은 rvalue 캐스팅이 아닌 상황에 따라 달라지는 캐스팅
  return static_cast<T&&>(arg);
}
*/

// decay -> const도 없애서.. 
// 우리는 reference도 없애야함.
// decltype(auto) 
template<typename T> remove_reference_t<T>&& xmove(T&& arg)
{
  // xmove(lvalue) : T 는 int&
  // xmove(rvalue) : T 는 int
  // 즉, 아래 캐스팅은 rvalue 캐스팅이 아닌 상황에 따라 달라지는 캐스팅
  return static_cast<remove_reference_t<T>&&>(arg);
}

// _NODISCARD : return 값을 무시하지마라. C++17에 나옴.

int main()
{
  Point p1(1,2);
  Point p2 = p1; // copy
  Point p3 = static_cast<Point&&>(p2); // move
  Point p4 = move(p3);
  Point p5 = xmove(Point(1,2));

  // 아래 함수는 어떤 생성자를 호출할까요?
  // 1. 인자가 2개인생성자
  // 2. 복사 생성자
  // 3. move생성자

  Point pt = Point(1,2); // ?? 

  // C++98 : 임시 객체를 만들고 복사 생성자로 pt에 복사 -> 1, 2
  // C++11 : 임시 객체를 만들고 move 생성자로 pt에 전달 -> 1, 3
  //  하지만 많은 컴파일러가 최적화 하면서 복사 생성자, move 생성자 
  //  호출을 생략!
  // C++17 : 최적화가 아니라 문법으로 고정됨. 

  // gcc a.cpp -std:c++98 -fno-elide-constructos
  // gcc a.cpp -std:c++17 -fno-elide-constructos
  // gcc a.cpp -std:c++11 -fno-elide-constructos

}
