// 4_EMPTY - 73page
//
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
  //vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
  list<int> v = { 1,2,3,4,5,6,7,8,9,10 };

  auto p = v.begin();
  ++p; // 나쁘지 않은 코드, 좋은 코드=> 모든 반복자에 다 적용이 가능함.
      
  p = p + 5; // 제일 쉬운것.
             // 모든 반복자가 다 되는 것이 아니라 임의접근만 된다.
             // list 반복자는 +연산안됨.
             //
  // ++ 해놨더니. vector써.. 

  // 조사해서 사용하면 됨. p 가 임의 접근이면 : p = p + 5;
  //                            아니면 ++p 를 5번
  advance(p,5);                  
  cout << *p << endl;

}




