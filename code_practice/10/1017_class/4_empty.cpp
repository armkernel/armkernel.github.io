// 4_EMPTY - 73page
//

#include <iostream>

using namespace std;

// Empty 클래스 : non static member data와 가상함수가 없는 클래스
class Empty{;

int main()
{
  Empty e;
  cout << sizeof(e) << endl; // 1
  // size가 1로 고정되어있음 empty는 약속..

}




