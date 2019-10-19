#include <iostream>

using namespace std;

template <typename ... Types>
void foo(Types ... args)
{
  // args에 있는 모든 요소를 화면 출력해보자.
  ( cout << ... << args );
  // 초기 값 op ... op args 
  // (((cout << E1) << E2) << E3) << E4
  // fold expression을 이용해 
  //  단순히.. 연산자가 + , - 가아니라
  //  초기값이 객체라면.. 연산자 재정의로 엄청난 일을 할 수 있다.

}

int main()
{
  // cout << 1;
  // cout에서 1을 출력하고 싶으면, 위와 같이 하면 됨.
  // return 값은 cout이다.
  // (((cout << 1) << 2) << 3);
  //
  foo ( 1,2,3 );
}
