// 8_value_category

#include <iostream>

using namespace std;

struct Animal
{
  virtual void Cry() { cout << "Animal Cry" << endl; }
};

struct Dog : public Animal
{
  virtual void Cry() { cout << "Dog cry" << endl; }
};
Dog d;

Animal  f1() // 왼쪽에 올 수 없다. move 호출
{
  return d;
}

Animal&& f2() // rvalue 이다. 따라서, 왼쪽에 올 수 없다.
{
  return move(d);
}

Animal& f3() // 왼쪽에 올 수 있다. copy 호출
{
  return d;
}

int main()
{
  f2();
  // 계속 d다.
  f1().Cry(); // 값을 부른다 => animal부름 다형성 없다.
  f2().Cry(); // Dog 부름
  f3().Cry(); // 참조를 부른다. Dog 부름 다형성 있다.

  Dog d1 = f1(); // move
  Dog d2 = f2(); // move
  Dog d2 = f3(); // copy 
}

// expression : 하나의 값으로 계산될 수 있는 코드 모음
//
// lvalue : 표현식의 결과가 lvalue참조
// xvalue :  표현식의 결과가 rvalue 참조
// prvalue : 표현식의 결과 값 (literal, 임시객체)
//
f1(); // 값반환
f2(); // rvalue 참조 반환
f3(); // lvalue 참조 반환

int main()
{
  int n = 10;
  static_cast<int&>(n) = 10; // 메모리가 반환. lvalue 가능.
  static_cast<int&&>(n) = 10; // 메모리 있는데 왼쪽에 못옴.. <- 분류 필요..
                                // xvalue
  //    iM
  // prvalue =:> pure r value. 오른쪽에 놓임 <= move 부름
  //  - 가상함수가 불리지 않음
  // xvalue => rvalue (expiring rvalue)

  // 사실은 value가 3개 

  //  lvalue , xvalue <= identity가 있다.
        Im     IM  

  n+1 = 10;                   // 값(11)   반환 왼쪽에 올 수 없음.

  Point pt;
  
  // 아래 코드는 lvalue를 rvalue(xvalue) 를 캐스팅하고 있습니다.
  Point pt 2 = static_cast<Point&&>(pt);
}
