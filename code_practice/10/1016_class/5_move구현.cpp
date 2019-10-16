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
};

int main()
{
  People p1("kim", 10, "seoul");
}

