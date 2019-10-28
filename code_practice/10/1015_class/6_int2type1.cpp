#include <iostream>

using namespace std;

// template 은 2번 컴파일 함.
// 1. T와 관련 없는 부분의 오류를 조사한다.
//    T와 관련 있는 코드는 조사하지 않는다.
//
// 2. 실제 사용하면 T타입이 결정되고.. 실제 함수(클래스) 의 코드가 생성됨
//    생성된 함수를 다시 컴파일(오류 조사)함.

template<typename T> void foo(T a)
{
  *a = 10;

  goo(a);
  // 뭘 찾을지 몰라. 밑에서 사용한적이 없어.. 뭘 찾을지 몰라.
  // a를 몰라.. 그래서 에러 안남

  //goo();
  // 이건 컴파일 하면 에러. 내가 부를게 뭔지 안다.
}

int main()
{
  //foo(10);
}
