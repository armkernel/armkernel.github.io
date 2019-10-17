#include <iostream>
#include <functional> // bind

using namespace std;
using namespace std::placeholders; // _1 _2 _3 .. 을 사용하기 위해 


void foo(int a, int& b) { b = 100; }

int main()
{
  function<void(int)> f;
  /*
  {
  int n = 0;

  f = bind(&foo, _1, n);
  // bind 는 복사본을 가지고 있다.
  // n의 값을 복사해서 보관한다.
  // 왜 참조로 보관하지 않을까?
  //  {} 을 쳐서 생각해보자.
  //  지역변수였다면.. dangling reference가 됨
  //  그래서 복사해서 가지고 있어야함
  }*/

  int n = 0;

  f = bind(&foo, _1, ref(n)); //참조로 보관하고 싶을 때, ref()쓰면 된다.
  f(10);

  cout << n << endl;
}

