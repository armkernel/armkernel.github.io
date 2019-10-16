// move구현 1
//
#include <iostream>
#include <string>

using namespace std;


// Rule of 5
// 포인터가 있고 생성자에서 자원 할당하면,
// 소멸자, 복사생성자, 대입연산자가 필요하다.
// C++11 : "move 생성자" , "move 대입연산자"
//
// 이 소스의 핵심 - move 생성자, move 대입연산자 만드는 방법


class People
{
  string name;
  int age;
  char* addr; // 문자.. -> string 편하지만 수업을 위해
public:
  People(string n, int a, const char* ad) : name(n), age(a)
  {
    addr = new char[strlen(ad) + 1];
    strcpy(addr, ad);
  }
  ~People() { delete[] addr; }

  People(const People& p) : name (p.name), age(p.age)
  {
    cout << "copy constructor" << endl;
    addr = new char[strlen(p.addr) + 1];
    strcpy(addr, p.addr);
  }

  People& operator=(const People& p)
  {
    cout << "copy = " << endl;
    if( &p == this ) return *this;
    name = p.name;
    age = p.age;

    delete[] addr;
    addr = new char[strlen(p.addr) + 1];
    strcpy(addr, p.addr);
    return *this;
  }

  // move 생성자
  // 중요 !! : 모든 멤버에 대해서 move로 옮겨라
  // age는 int라서 상관없다.
  People(People&& p) : name (std::move(p.name)), 
                       age(p.age),
                       addr(p.addr)
  {
    cout << "move constructor" << endl;

    p.addr = nullptr;
  }

  // move 대입
  People& operator=(People&& p)
  {
    cout << "move = " << endl;
    if( &p == this ) return *this;

    name = std::move(p.name);
    age = p.age;

    delete[] addr;
    
    addr = p.addr;
    p.addr = nullptr;
    p.age = 0;

    return *this;
  }

};

int main()
{
  People p1("kim", 10, "seoul");
  People p2 = p1; // 복사생성자 
  p2 = p1;        // 복사 대입 연산자

  People p3 = move(p1); // move 생성자
  p3 = move(p2);        // move 대입 연산자

  //n = move(n); // undefined 이렇게 사용하지 말라는 것. 결과는 다를 수 있다.
}

