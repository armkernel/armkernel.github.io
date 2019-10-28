// 9_완벽한전달3

#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}
// 완벽히 전달하려면
// 1. 인자는 복사본이 생성되면 안된다. - 참조
// 2. const 붙여도 안된다.
// 3. int& 와 int&& 버전의 함수를 2개 제공한다.
//  (const int&, const volatile int& 등도 필요하다.)

// 완벽하게 전달하고 싶은 거다.

template<typename F, typename T> 
void chronometry(F f, int& arg)
{
  f(arg);
}

// main -     chronometry       hoo
// 10(rvalue)전달 => int&& arg => 받고 나니 lvalue-> 메모리는 변한 것 없는데.. value속성이 바뀜.
// 속성을 변경해야함.

template<typename F, typename T> 
void chronometry(F f, int&& arg)
{
  f(static_cast<int&&>(arg));
  // int&& arg = 10; 
  // 10 : rvalue
  // arg : lvalue - 이름이 있음
  // hoo(int&)찾게됨.
}

int main()
{
  hoo(10); //ok

  chronometry(hoo,10); // 되야한다.
}
