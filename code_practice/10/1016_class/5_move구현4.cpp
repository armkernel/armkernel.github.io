// move구현 1
//
#include <iostream>
#include <string>

using namespace std;

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
  // move 계열 함수를 만들 때
  // 1. 예외가 발생하지 않게 만들고
  // 2. 함수 () 뒤에 neexcept를 적으세요.
  //
  // 선언만 봐서는 이게 예외가 있는지 알 수 없어.
  // noexcept를 적어줘야함.
  // 만약 예외가 발생하면, 데이터 손실이 나타남.
  // People(People&& p) noexcept 
  //
  
  // noexcept : 예외가 없다.
  // noexcept(false) : 예외가 있다.
  // noexcept(true)  : 예외가 없다.

  // or 해서 엮으면 됨.
  People(People&& p) noexcept (is_nothrow_move_constructible<string>::value)
    : name (std::move(p.name)), 
                       age(p.age),
                       addr(p.addr)
  {
    cout << "move constructor" << endl;

    p.addr = nullptr;
  }

  People& operator=(People&& p) noexcept
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

#include <vector>

int main()
{

  People p("kim", 5, "seoul");

  People p1 = p;        // 무조건 복사 생성자
  People p2 = move(p);  // 무조건 move 생성자
  People p3 = move_if_noexcept(p2); // 예외가 없을 때만 move
                                    // 예외가 있으면 copy
                                    //
  // move_if_noexcept 원리
  People p4 =
      is_nothorow_move_constructible<People>::value ? move(p3) : p3;

  // 결론.
  //  STL vector같은거 쓸 때, 생성자 만들고 noexcept을 안 붙이면 효과 못봄
  //  move는 예외가 거의 안나옴.
  //  pointer만 복사하기 때문에.. memory할당이 없다.
  //  String에서 move생성자 할 때, 예외가 발생하면..?

  vector<People> v(3, People("kim", 5, "seoul") ); // 왜 에러일까..? default없어서

  cout << "-------------------" << endl;
  
  v.resize(5, People("kim", 5, "seoul"));

  cout << "-------------------" << endl;

}

