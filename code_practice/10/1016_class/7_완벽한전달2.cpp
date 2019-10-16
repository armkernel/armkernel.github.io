// 7_완벽한전달1
//
#include <iostream>
using namespace std;

int main()
{
  typedef int& LREF;
  typedef int&& RREF;

  int n = 10;

  LREF r1 = n;
  RREF r2 = 10;

  // typedef나 템플릿의 경우는 reference의 reference 가능
  // reference collapsing ( 레퍼런스 붕괴 (축약) )

  // 양쪽이 두개일때만 두개 나머지는 하나
  // int& & => &
  // int&& & => &
  // int& && => &
  // int&& && => &&

  LREF& r3 = n ;
  RREF& r4 = n ;

  LREF&& r5 = n;
  RREF&& r6 = 10;
}
