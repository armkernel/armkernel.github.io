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
  else
  {
    // 살아 있는 경우..
    // cout << sp1->bestFriend->name << endl;
    // 접근이 안돼.. => compile error
    // shared_ptr 만들어야해
    
    shared_ptr<People> sp = sp1->bestFriend.lock();

    if(sp)
    {
      cout << sp -> name << endl;
    }
  
    // weak 는 소유권이 없어
    // 안전한 객체 접근을 하기 위해서는 shared_ptr로 변경해야해
    // 안전함을 위해서 이렇게 설계
  }
}
