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

// 규칙 1. 복사 계열과 move 계열을 모두 제공하지 않으면
//         컴파일러가 모두 디폴트 버전을 제공해준다.
//      2. 복사 생성자를 만들면 더이상 move 생성자의 디폴트 버전을 
//        제공하지 않는다.
//        move() 사용시, 복사 생성자를 사용하게 된다.
//        둘다 만들거나 다 안만들거나 해야함.

//      3. 로깅만하고 싶다..?

class Home
{
  People p;
public:
  Home() : p("kim",10, "seoul") {}

  Home(const Home& h) : p(h.p)
  {
    cout << "Home Copy Constructor" << endl;
  }

  Home(Home&&) = default; // default move 생성자를 만들어라.
};


int main()
{
  Home h1;
  Home h2 = h1;
  Home h3 = move(h1);

}

