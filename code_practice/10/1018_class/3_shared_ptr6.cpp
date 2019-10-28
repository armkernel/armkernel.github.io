#include <iostream>
#include <string>
#include <memory>
using namespace std;

struct People
{
  string name;

  People(string n) : name(n) {}
  ~People() { cout << name << " 파괴" << endl; }

  //shared_ptr<People> bestFriend; // 참조 계수 증가한다.

  // People* bestFriend; // 참조계수가 증가하지 않는다. 

  weak_ptr<People> bestFriend; // 참조 계수가 증가하지 않는
                               // 스마트 포인터.
                               // 장점: 객체 파괴 여부 조사가능
};

int main()
{
  shared_ptr<People> sp1 = make_shared<People>("kim");
  {
    shared_ptr<People> sp2 = make_shared<People>("lee");

    sp1->bestFriend = sp2;
    sp2->bestFriend = sp1;  // weak는 shared랑 호환된다.
  }

  if (sp1->bestFriend.expired())
  {
    cout << "객체 파괴됨" << endl; // ??
  }
}
