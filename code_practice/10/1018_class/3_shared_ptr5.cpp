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

  People* bestFriend; // 참조계수가 증가하지 않는다.
                      // 객체가 파괴 되었는지 알 수 없다.
                      // Dangling Pointer 의 위험이 있다.
};

int main()
{
  shared_ptr<People> sp1 = make_shared<People>("kim");
  {
    shared_ptr<People> sp2 = make_shared<People>("lee");

    // 서로가 서로를 가리킨다.
    // .get() ; <- raw pointer
    sp1->bestFriend = sp2.get();
    sp2->bestFriend = sp1.get(); 
  }

  // 진짜 포인터가 다시 들어오면 dangling pointer 즉, 죽었는지 알 수 없다.
  // 객체가 파괴 된 것을 조사할 수 없는 문제가 생김.
  if (ps1->bestFriend != nullptr)
  {
    cout << sp1->bestFriend->name << endl; // ??
  }
}
