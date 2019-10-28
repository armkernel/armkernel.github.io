// move구현 1
//
#include <iostream>
#include <string>

using namespace std;

class People
{
  string name;
  int age;
  //char* addr; // 문자.. -> string 편하지만 수업을 위해
  string addr;
public:
  People(string n, int a, string ad) : name(n), age(a) , addr(ad)
  {
  }
};

#include <vector>

int main()
{
  People p("kim", 5, "seoul");

}

