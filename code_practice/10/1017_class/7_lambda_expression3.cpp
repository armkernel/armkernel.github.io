#include <iostream>

using namespace std;

class Test
{
public:
  void hoo(int a) { cout << " Test::hoo" << endl; }
}




void goo(int a, int b) { cout << "goo" << endl; }

template<typename T, typename ... ARGS> 
void foo(T&& f, ARGS&& ... args)
{
  f(std::forward<ARGS>(args)...);
}

int main()
{
  foo(goo, 1, 2);

  foo(&Test::hoo, 10);

  // 멤버함수 포인터 만드는 방법
  //void(*f)(int) = &Test::hoo; // 이 친구를 담을 수 없다. this가 들어감.

  //void(Test::*f)(int) = &Test::hoo; // 핵심 1.

  // f(10); // ?안돼 error. 객체가 없다.

  Test test;
  //test.f(10); // 안돼.. 함수 포인터야. f라는 멤버함수가 없다.

  //test.*f(10); // .* 연산자 -> 너를 안에 찾아보면.. 멤버가 있을 거야
              // pointer to memober.
              // 우선순위 문제로 에러
              //
  (test.*f)(10); // 핵심 2. 멤버 함수 포인터로 함수 호출하는 코드

  // 위 코드 보다 아래코드가 더 좋다.
  //f(&test, 10);

  // 그래서 invoke를 만들었다. c++17
  //
  invoke(f, &test, 10);


}
