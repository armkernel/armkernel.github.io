// 2. forwarding reference1


#include <iostream>

using namespace std;

int main()
{
  int n = 10;

  // 오른쪽 걸보고 타입을 결정해달라
  // 복사본
  auto a1 = n; // ok
  auto a2 = 10; // ok

  // 참조..
  auto& a3 = n; // lvalue니까 가리키는것 문제 없음
  auto& a4 = 10; // 오른쪽이 rvalue라서 컴파일 하면 에러 

  // Rvalue가 아님.
  // auto => T랑 똑같다.
  // foo (T arg); foo(10) => 10을 보고 T를 결정
  // auto arg = 10; => 10을 보고 auto 결정 
  auto&& a5 = n;  // ok.
  auto&& a6 = 10; // ok.

  vector<bool> v(10, 0);

  auto a6 = v[0];  // ok
  auto& a7 = v[0]; // error
  auto&& a8 = v[0]; // ok

  //temporary로 받음
  
  for (auto&& n : v) // rvalue아니라 forwarding reference다.
  {

  }
}
