#include <iostream>
using namespace std;

class Test
{
public:
  //void foo() { cout << "&" << endl; } // 모든 객체가 호출 가능.
  void foo() & { cout << "&" << endl; } // 이름 있는 객체만 사용가능
  void foo() && { cout << "&&" << endl; } // temporary 객체만 사용가능

  // 많이 쓰지 않는다. 모든 경우에 되게 합시다 하면 쓸 수도..
};

int main()
{
  Test t;
  t.foo();

  Test().foo();

  ((Test*)0)->foo(); // & ? && 주소가 있으니.. 안돼
}
