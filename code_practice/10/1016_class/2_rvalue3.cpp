#include <iostream>

using namespace std;

int main()
{
  int n = 10;
  int* p = &n;
  
  // decltype 규칙 1. 변수 이름만 있는 경우
  //                  해당 변수의 선언을 조사해서 타입 결정

  decltype(n) d1; // int 타입 -> int d1
  decltype(p) d2; // int*
  // 뭔가를 집어넣으면, 인자로 전달받은 타입으로 바꿈.

  // decltype 규칙 2. 변수에 연산자가 포함된 표현식이 있는 경우
  //               해당 표현식이 등호의 왼쪽에 올 수 있느냐?
  //               올 수 있으면, 참조. 아니면 값
  decltype(*p)  d3; // int& d3; 초기 값이 없으므로 에러
  decltype(n+1) d4; // int d4; // lvalue 참조 rvalue면 값 
  decltype(++n) d5; // int& d5;
  decltype(n++) d6; // int d6;

  decltype(n)   d7; // int
  decltype(10)  d8; // int

  // 변수 이름 + 괄호 2번째 규칙을 적용해야함
  decltype((n))   d9; // int&
  decltype((10))  d10; // int

}
