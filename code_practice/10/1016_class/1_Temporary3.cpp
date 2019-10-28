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

// Tempoary의 활용
// 1. 함수 인자로만 사용할 객체라면 temporary를 사용하는 것이 좋다.
// 2. 함수가 temporary를 받으려면 const 참조로 해야한다.
void foo(const Point& p) 
{
}

int main()
{
  // Point p (0,0);
  // foo(p);
  // 인자로만 보낼 꺼다. 필요없으면, 빨리 파괴되는게 좋지 않을까?
  // Point 객체를 생성한 후 인자로 전달하면.. 파괴하는 시간이 block이 마지막까지 가서 만난 후 파괴됨

  // 함수의 인자로 보낼 때, temporary를 보냄.
  //
  // 전달 받는 곳에서 const를 붙여서 받아야함. 안되면.. 인자를 전달받지 못해.
  // const를 붙이는 이유가 실수로 바꾸기 위해 바꾼다.. 그용도 뿐만아니라 temporary를 받게 해준다는
  // 용도도 있다.
  foo(Point(0,0));

  cout << "------" << endl;
}
