#include <iostream>
using namespace std;

class Car
{
public:
  Car() {}

// 소멸자를 protected 를 부름
// 객체가 파괴 될때, 소멸자를 부른다.
// 하지만, protected에 있을 경우 외부에 선언에 의해 파괴 될 수 없다.

  void Destory() { delete this; }
  // 멤버함수를 통해서 하라고..

protected:
  ~Car() { cout << "~Car" << endl; }
};

int main()
{
  Car c;
  // 스택에 객체를 만들 수 없다.
  // 대신 heap에는 만들 수 있다.
  // 만들면, 자동으로 소멸자가 불리는게 아니라서 가능
  Car* p = new Car;

  // 꼭 delete를 외부에서 하는 것이 아니라,
  // 멤버함수를 만들어 가능
  // delete p; 
}



// protected 소멸자
// 객체를 스택에 만들 수 없게 한다. 
// 객체를 힙에는 만들 수 있게함.
// 참조계수 기반 객체 수명 관리 기법에서 주로 사용된다.


