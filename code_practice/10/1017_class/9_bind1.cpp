#include <iostream>
#include <functional> // bind

using namespace std;
using namespace std::placeholders; // _1 _2 _3 .. 을 사용하기 위해 


void foo(int a, int b, int c, int d)
{
  printf("%d %d %d %d\n", a, b, c ,d);
}

int main()
{
  foo(1,2,3,4); // 4항 함수

  // bind : M항 함수를 N항 함수로 변경 단, N < M;
  // 첫번째 인자로 함수를 주세요.
  // 함수 인자 갯수 만큼 줘야함.
  // 인자 4개 고정해달라.
  bind(foo, 1,_1,_2,_3) (7,8,9); // 4항 함수를 => 무항 함수
  // foo(1,7,8,9); //이 함수로 호출하는것. 
  // 4항함수를 3항으로 바꿈.

  bind(foo, 9,_2,_1,7) (6,4); // 9,4,6,7 나오게

}
