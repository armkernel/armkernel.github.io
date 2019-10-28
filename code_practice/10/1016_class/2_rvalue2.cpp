#include <iostream>

using namespace std;

// 핵심 value category는 객체가 아닌 표현식(expression)에 대한 개념
//
// statement : ; 으로 종료되는 한줄의 코드 모음
// statement 는 여러개의 expression으로 구성됨. 
//
// expression : 하나의 값으로 계산될 수 있는 코드 모음.
int main()
{
  int n = 10;
  
  n = 20; // ok  n 은 lvalue

  n + 1 = 20; // ?
  // = 왼쪽에 있으려면 memory가 있어야함.
  // n+1이라면.. 메모리가 할당 된게 아니라 값임. 왼쪽에 올 수 없어 

  n + n = 20; // error n+n 은 rvalue
  // 내가 할당한적있는 메모리를 반환하는 것인가 값을 반환할 것인가 

  n = 3;

  ++n = 20; // 참조니까 왼쪽에 올 수 있다.
  // 이렇게 쓸일 은 없다.
  // 중요: 어떤 연산자의 결과가 
  //       "값" 일지 "참조" 일지 잘 생각해야함.
  n++ = 20;

  n = 3;

  int s = ++n * ++n;
  cout << s << endl; // 25

}

// 전위형 ++을 만들자
// 넘어갈 떄, & 필요없다.
/*
int& operator++(int& n)
{
  n = n + 1;
  return n; 
}
*/

// 후위형 ++
int operator++(int& n, int)
{
  // 지역 변수라서 참조리턴 못함
  // 값 리턴해야함
  int temp = n;
  n = n + 1;
  return temp; 
}
