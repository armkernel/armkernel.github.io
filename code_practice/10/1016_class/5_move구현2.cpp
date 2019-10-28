// move구현 1
//
#include <iostream>
#include <string>

using namespace std;

// Rule of 3 
// 포인터가 있고 생성자에서 자원 할당하면,
// 소멸자, 복사생성자, 대입연산자가 필요하다.
//

// 이 소스의 핵심 - 복사생성자, 대입연산자 만드는 방법.

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

  // 복사 생성자 : 클래스 내 pointer있다면 반드시 만들어야함
  People(const People& p) : name (p.name), age(p.age)
  {
    // 포인터가 아닌 멤버는 그냥 복사해도 되지만,
    // 포인터는 메모리를 복사 (또는 참조 계수)
    addr = new char[strlen(p.addr) + 1];
    strcpy(addr, p.addr);
  }

  // 대입 연산자 
  // 복사 생성자를 만든 경우는 대부분 대입 연산자도 필요하다.
  // 규칙 1. 대입의 반환값은 참조이다.
  //      2. 자신과의 대입을 조사한다.
  //      3. 혹시 클래스가 상속받았다면, 기반클래스의 대입 연산자도 호출해라.
  //      4. 예외에 안전하게 작성해야한다. - 교재 (copy and swap)
  People& operator=(const People& p)
  {
    if( &p == this ) return *this;
    // 포인터가 아니면 그냥 대입
    //
    // Base::operator=(p);
    name = p.name;
    age = p.age;

    // 포인터는 기존 메모리를 제거하고, 새로운 메모리 복사
    delete[] addr;
    addr = new char[strlen(p.addr) + 1];
    strcpy(addr, p.addr);
    return *this;
  }

};

int main()
{
  People p1("kim", 10, "seoul");

  p1 = p1; // 자기 자신과의 대입을 확인해야함.

  People p2 = p1; // 복사생성자. default는 shallow copy
  // 위에것은 만들때 집어넣음
  // 아래는 만들고 집어넣음.
  // 컴파일러가 만들어준다. => shallow copy
  p2 = p1;
  //별도의 동작 처럼 보임
  
  int n = 10;
  (n = 20) = 30; //이거 되야함. n = 20 -> 수행 후 30;
  // n이 왼쪽에 있음. 자기자신이 나와야함.
  // 자기 자신이 나와야하기 때문에 this를 반환해야함.
  // 값 반환이 아닌 참조로 반환해야해.
  
}

