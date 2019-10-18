#include <iostream>

using namespace std;

// 1. 헤더파일
#include <memory>

class Car
{
public:
  void Go() { cout << "Car Go" << endl; }
  ~Car() { cout << "~Car " << endl;}
};

int main()
{
  // 2. 생성자가 explicit 이므로 = 로는 초기화 안됨.
  // 안쓰는 이유가 있음

  // shared_ptr<int> sp1 = new int; // = 초기화는 안되고 ()만된다.
  shared_ptr<int> sp2(new int);

  // 3. 크기 : 대부분의 구현에서 raw pointer * 2
  cout << sizeof(sp2) << endl;
  // 일반적으로 shared ptr은 raw pointer의 2배

  // 4. -> 와 . 연산
  // 핵심
  // -> : 대상체의 멤버 함수
  // .  : shared_ptr 자체의 멤버 함수
  shared_ptr<Car> sp3(new Car);

  sp3->Go(); // Go는 대상체의 멤버함수, 객체

  int n = sp3.use_count(); // sp3는 shared ptr이기 때문에 .을 누르면 shared pointer의 
                         // 멤버함수가 호출됨
  Car* p = sp3.get(); // raw pointer 가져오기

  sp3.reset(); // if (--참조계수 == 0 ) delete; obj == nullptr;

}
