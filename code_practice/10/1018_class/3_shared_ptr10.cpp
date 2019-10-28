#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
  int* p1 = new int;

  // 아래 코드는 좋을까요?
  shared_ptr<int> sp1(p1); // 자신 만의 관리 객체가 또 만들어짐.
  shared_ptr<int> sp2(p1); // 이 순간, 또다른 관리객체로 관리함.

  // 핵심: 자원을 획득 한 후, 자원의 포인터를 자원 관리 객체에 넣지 말라.!

  // 자원의 획득은 자원 관리 객체가 만들어 질때, 동시에 생성해야한다.

  //RAII : Resource Acquision Is Initialization
  shared_ptr<int> sp3(new int); // 이렇게 하라는 것.
                                // 물론, make_shared가 더 좋다.
}
