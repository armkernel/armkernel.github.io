//4_move

#include <iostream>
using namespace std;

class Point
{
  int x,y;
public:
  Point(int a = 0, int b = 0) : x(a), y(b) {}

  // 복사 생성자 모양 1. call by value
  // 복사 생성자가 무한히 호출되는 표기법 - 컴파일 에러
  // Point(Point pt) {} // Point pt = p2 => Point pt(p2)
  // 복사생성자가 무한히 불림. 재귀적으로 불림..
  // 첫 번째 매게 변수는 만들 수 없다.
  //
  // 모양 2. call by reference
  // 사용가능 문제없음.
  // 함수 반환값을 받지 않는다.
  // 단점. rvalue(임시 객체) 를 받을 수 없다.
  //       값을 반환하는 함수의 반환값을 받을 수 없다.
   Point(Point& pt) {}
  //
  // 모양 3. call by const lvalue reference
  // lvalue 뿐 아니라 rvalue 모두 받을 수 있다.
  // 가장 좋은 표기법
  //Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

Point foo()
{
  Point p;
  return p;
}

int main()
{
  Point p1; // default 생성자
  Point p2(1,2); // 인자 2개인 생성자
  Point p3(p2); // ? Point (Point); 자기 자신과 동일한 모양이 필요함.
  // 우리가 만들 수 있다.
  
  Point ret = foo(); //Point ret (foo())
}
