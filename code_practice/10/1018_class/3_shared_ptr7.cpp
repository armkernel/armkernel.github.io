#include <iostream>
#include <string>
#include <memory>
using namespace std;

struct People
{
  string name;

  People(string n) : name(n) {}
  ~People() { cout << name << " 파괴" << endl; }
  
  weak_ptr<People> bestFriend; 
};

int main()
{
  shared_ptr<People> sp1;
  weak_ptr<People> wp;

  shared_ptr<People> sp2 = make_shared<People>("kim");
  //sp1 = sp2; // 복사하면 참조 계수가 2가됨.

  wp = sp2;

  cout << sp2.use_count() << endl;

  // ---------------------------------------
  //
  shared_ptr<People> sp3 = make_shared<People>("lee");

  shared_ptr<People> sp4 = sp3;
  weak_ptr<People> wp4 = sp3;

  //아래 코드들은 항상 안전할까?
  //
  string s1 = sp4->name; // sp4가 살아있는 동안 객체는 파괴 될 수 없다.
                         // dangling pointer가 나올 수 없다.

  string s3 = wp4->name; // check 안하고 쓰면 dangling 포인터. 생길 수 있다.
                         // 그래서 weak_pointer에는 -> 재정의 안되있다.
                         // 가면 위험하다.
                         // 왜? 체크를 무조건 해야하는데 사용자가 하지 않고 쓸 경우 대비
                         // -> 와 * 연산자가 재정의 되어 있지 않다.
                         // 참조 계수를 올리는 방법은 shared_ptr를 만드는 방법 밖에 없다.

  // wp가 가리키는 객체에 접근하려면
  // 참조계수를 올리고 접근해야한다.
  // 참조계수를 올리는 방법은 "shared_ptr"을 만들어야한다.

  shared_ptr<People> sp5 = wp4.lock(); // 만드는 동안에 lock을 걸게.. 만드는 동안에 죽으면 안돼
                                       // multi thread 환경에서 안전
                                       // 오기 전까지 파괴 될 수도 있음
                                       // 그래서 if문으로 체크
  // 참조계수가 또 올라가는거아니야:?
  // 멤버에 있으면, 문제가 있지만 => 외부에 있으면 문제 될 건 없다.
  // 멤버 변수는 객체가 파괴 될때 문제.

  if(sp5)
  {
    //이제는 안전하게 접근가능
    string s3 = sp5->name;
  }
}
