#include <iostream>

using namespace std;

class Animal
{
// 생성자를 만들 때, protected에 넣는다.
// 디자인 관점에서 생각해보자.

protected:
  Animal() { cout << "Animal" << endl; }
  // 나는 외부에서 객체로 만들 수는 없지만, 자식에서는 만들 수 있게 하겠다. 
  // 현실 세계와 비슷하다.
  // 추상 클래스 모델링할 떄 좋음.
};

// 정리
// 생성자의 정확한 호출 순서
// 1. Dog 생성자가 먼저 호출 된다.
// 2. Dog의 생성자 내 기반 클래스 인 Animal의 생성자를 호출한다.
//
// 생성자를 protected에 만드는 이유
// 자기 자신을 만들수는 없다.
// 하지만 파생 클래스에서는 객체를 만들 수 있다.
// 동물은 추상적인 개념이기 때문에 객체가 존재할 수 없지만 강아지는 존재가능 

class Dog : public Animal
{
public:
  Dog() { cout << "Dog" << endl; }
};

int main()
{
  // 생성자가 protected에 있으니 에러가 날 것임
  // Animal a;
  Dog    d; // Dog 객체를 만들면, 기반 클래스가 먼저 불리고 dog객체가 불린다.

  // Dog의 객체를 만들면, Dog 생성자가 먼저 불림. // 컴파일러가 : Animal()의 생성자를 추가해주는 것임.
  // 호출은 Dog로 먼저가고 이후 Animal()이 불림
  //
  //  Dog호출은 문제 없다. 아무리 protected 라고 되어있더라도 파생에서는 기반을 부를 수 있다.

}
