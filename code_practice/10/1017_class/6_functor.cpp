// 6_함수 객체
// 함수 객체 (function object) : 함수 처럼()를 사용해서 호출가능한 객체
#include <iostream>

using namespace std;

// 요즘은 "Callable Object" 라는 용어 사용
struct Plus
{
  int operator()(int a, int b)
  {
    return a + b;
  }
};

int main()
{
  Plus p; // 함수가 아니라 객체.

  int n = p (1,2); // 핵심!

  // a + b; compiler : a.operator+(b);
  // a - b; a.operator-(b);
  // a();   함수라면 그냥 호출.. 객체라면.. a.operator() ();
  // a(1,2); a.operator()(1,2);
  //
  // 그냥함수 만들지..
  // 왜?
  
}
