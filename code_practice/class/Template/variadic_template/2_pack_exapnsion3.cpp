#include <iostream>
#include <tuple>

using namespace std;

template<typename ... Types> void foo(Types ... args)
{
  int x[] = { args... };

  // type 2개를 넣어야함.
  // 아래의 표현도 가능하다.
  pair<Types... > p1; // pair<int, double> p1;
}

int main()
{
  foo(1, 3.4);
}

// 또다른 예제
// pack expansion example

