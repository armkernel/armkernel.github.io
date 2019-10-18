#include <iostream>
#include <string>
#include <memory>
using namespace std;

struct People
{
  string name;

  People(string n) : name(n) {}
  ~People() { cout << name << " 파괴" << endl; }

  shared_ptr<People> bestFriend;
};

int main()
{
  shared_ptr<People> sp1 = make_shared<People>("kim");
  shared_ptr<People> sp2 = make_shared<People>("lee");

  // 서로를 가리킨다. (cycle reference) - 버그. 메모리 삭제 안됨
  // 메모리 누수
  // 멤버 데이터는 수명에 관여 하면 안된다.
  // 증가 하면 안돼.
  // 참조 계수를 증가시키지 않는 포인터가 필요하다.
  sp1->bestFriend = sp2;
  sp2->bestFriend = sp1;
}
