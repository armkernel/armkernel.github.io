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
  // shared_ptr<People> sp1 = make_shared<People>("kim");

  shared_ptr<People> sp(new People("kim"));
  weak_ptr<People> wp = sp;

  // 
  // 관리 객체 
  // 참조 카운트 (strong count)
  // 주소(객체)
  // weak count -> 실제 지우기 
  // 삭제 정보

  // make_shared로 만들면.. 붙어있는데.. 관리 객체를 어떻게 지워?
  // 못지워..
  // wp가 지워질때 까지 실제 메모리 반납은 미뤄진다.
  // 소멸자를 부르긴 한다 명시적으로.
  // 메모리 삭제가 조금 늦춰지는게 단점.
}
