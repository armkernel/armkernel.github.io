// 6_함수 객체
// 함수 객체 (function object) : 함수 처럼()를 사용해서 호출가능한 객체
#include <iostream>

using namespace std;

// 0 ~ 9 사이의 난수를 구하고 싶다.
// 단, 중복되지 않게 하고 싶다. 어딘가에 나온 것들을 저장해야함.
// 전역변수에 저장? 노..
//
// 함수는 동작이 있다.
// 상태 없다. <- 이게 문제다.
//
// core!! 함수는 동작은 있지만, 상태가 없다.
int random1()
{
  return rand() % 10;
}

int main()
{
  for (int i = 0; i < 10; i++) 
    cout << random1() << endl;
}
