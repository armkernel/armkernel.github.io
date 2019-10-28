#include <iostream>

using namespace std;

template<typename T> class Test
{
public:
  void foo(T&& arg) {}

  // 아래 함수가 forwarding reference이다.
  template<typename U> void goo(U&& arg) {}
};


int main()
{
  int n = 10;

  Test<int> T; // 이 순간 T가 결정됨. int로 끝남.
  
  //호출하는 순간 type이 결정되야 forwarding reference이다.
  t.foo(n); // 1
  t.foo(10); // 2
  // 인자를 보고 결정함

  // 1,2 는 에러가 있을까요?
}
