#include <iostream>

using namespace std;

class Car
{
public:
  void Go() { cout << "Car Go" << endl; }
  ~Car() { cout << "~Car " << endl;}
};

// 아래 코드가 핵심
// 개념 : 임의의 객체가 다른 타입의 포인터 역활을 하는 것
// 원리 : ->와 *를 재정의 해서 포인터 처럼 보이게 한다.
//
// 장점 : raw pointer가 아닌 객체이다.
//        생성/복사/대입/소멸의 과정에 추가의 작업을 할 수 있다.
//        대표적 활용이 소멸자에서 자동삭제 가능.
//
class Ptr
{
  Car* obj;
public:
  Ptr(Car* p = 0) : obj(p) {}
  Ptr() { delete obj; }
  Car* operator->() { return obj; }
  Car& operator*() { return *obj; }
};


int main()
{
  Ptr p = new Car; // Ptr p(new Car); 내부적으로 포인터 변수가 있음
  // 메모리 그림
  // 포인터가 들어감.
  /*
   * -----
   * |*  | ----- > -----
   * |100|         |car|
   * -----         -----
   * */


  // 객체인데,, 포인터 처럼 쓰고 있다.
  // 객체가 Car인데.. 어떤 객체가 다른 객체의 포인터로 보인다. => smart pointer
  p->Go();  // (p.operator->())Go() 라는 모양이지만,
            // (p.operator->())-> Go() 처럼 해석한다.
            //
  (*p).Go(); // p.operator*()
  // 값리턴 아닌 참조리턴으로 가야한다.
  // 임시객체가 받아서 Go호출함.
  
  // 포인터는 block 벗어날 때, 사라지지 않음
  // 객체는 소멸자 부른다.
}
