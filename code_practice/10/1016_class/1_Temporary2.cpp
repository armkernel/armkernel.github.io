// 1_Temporary
// github.com/webkit
// webkit/source/wtf/wtf/scope.h 
//

#include <iostream>
using namespace std;

class Point
{
public:
  int x, y;

  Point(int a = 0 , int b = 0) : x(a), y(b)
  {
    cout << "Point()" << endl;
  }
  ~Point() { cout << "~Point" << endl; }

  void set(int a, int b) { x = a; y = b; }
};

// Temporary의 특징
//
// 특징 1. temporary는 lvalue가 될 수 없다. (등호 기준 왼쪽)
// 특징 2. temporary는 &연산자를 사용해 주소 구할 수 없다.
// 특징 3. temporary는 참조변수를 만들어 가리킬 수 없다.
// 특징 4. temporary는 const 참조는 가리킬 수 있다.
int main()
{
  Point p(0,0);
  p.x = 10;

  // Point(0,0).x = 10; // 밑에서는 못씀. 의미가 없다.
  // temporary는 lvalue가 될 수 없다.
  // 정확하게는 temporary의 멤버 데이터가 왼쪽에 있다. 
  // 질문: temporary 는 상수 일까요?
  //      상수는 아니다. 문법적으로 왼쪽에 올 수 없다는 것만 알 수 있다.

  Point(0,0).set(10,20); // 이건 허용됨.
  // Temporary에 상태를 바꿀 수 있는 경우는 뭐가 있는가?
  // BitProxy 에 operator=() 이걸 사용함. 
  // 많이 쓰이지는 않지만 간혹가다 쓰인다.

  Point* p1 = &p;
  //Point* p2 = &Point(0,0); // Temporary는 &연산자를 사용해서 주소를 구할 수 없다.
                          // 문장 끝 파괴 되는데.. 주소연산자를 구해서 사용할 수 없다.
                          // micro studio c++에서는 temporary 주소를 구할 수 있다.
                          // 언어 확장 사용 안함 -> 예로 고쳐야함. 컴파일 하면 에러남. c++표준.

  // 특징 3
  Point& r1 = p;
  //Point& r2 = Point(0,0); // 참조를 하면, 더이상 없는 객체를 가르켜야함. 그래서 이건 안됨.

  const Point& r3 = Point(0,0); // ok... const 참조는 temporary를 가리킬 수 없다.
  // 원래 사라지는데.. 그걸 가리키게 되면.. 사라진 곳을 가리키니 문제되는거아니야??
  // temporary를 const &로 가리키게 되면.. r3의 수명으로 연장됨. 
  // c++17에서 부터 용어가 생김.. => "temporary의 실체화!" temporary materlization

  // 문제가 있음.
  // 원본 객체는 상수가 아닌데.. const &를 사용하면 상수화 됨. 
  // temporary를 상수성을 추가하면서 문제가 됨.
  //

  // C++11 부터는 비상수 참조로 가리킬 수 없을까?
  //
  Point&& r4 = Point(0,0); // ok.
  r4.x =10;


}
