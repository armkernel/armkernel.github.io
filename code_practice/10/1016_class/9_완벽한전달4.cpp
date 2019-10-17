// 9_완벽한전달3

#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 100; }

// 완벽히 전달하려면
// 1. 인자는 복사본이 생성되면 안된다. - 참조
// 2. const 붙여도 안된다.
// 3. int& 와 int&& 버전의 함수를 2개 제공한다.
//  (const int&, const volatile int& 등도 필요하다.)

// 완벽하게 전달하고 싶은 거다.

template<typename F, typename T> 
void chronometry(F f, T& arg)
{
  f(arg);
}

template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
  f(arg);
}

int main()
{
  int n = 10;
  
  chronometry(foo, 10); // &로 하면 10이 안넘어감.

  chronometry(goo, n);

  cout << n << endl;
}
