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

int main()
{
  // Point p(1,1);
  // 이 객체는 이름이 있다. 
  // 아래에서 쓰려면, 이름을 사용해서 불러 쓰면 된다.
  // block을 만나면 파괴된다.
  //
  // named object, 단일 문장을 넘어서 메모리에서 사용가능
  // 수명: 객체를 생성한 블럭의 끝
  
  // Point(1,1); // unnamed object
  // c++ class이름에 괄호만 붙여도 객체가 만들어짐.
  // 이름 없는 객체 -> Temporary (object)
  // 아래에서 접근하고 싶다고 해도 사용할 수 없다.
  // 수명: 문장의 끝(;)
  // 단일 문장에서만 사용가능하다.
  // 소멸자의 호출 시점.. "------" 앞쪽.

  Point(1,1), cout << "X" << endl;
  // c++ 에서 (,)를 하면, 뒤에 다른 문장을 하나 더 적을 수 있다.
  // 그렇다는 말은 X가 먼저 출력되고 이후에 파괴되는 것을 확인할 수 있다.

  // 핵심1. temporary를 만드는 방법
  // 핵심2. temporary의 수명.
  cout << "----------------" << endl;
}
