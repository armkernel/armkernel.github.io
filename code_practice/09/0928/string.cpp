#include <cstdio>
#include <cstring>

#include <iostream>

using namespace std;

class String
{
  size_t sz;
  char* buff;
public:

  friend ostream& operator<<(ostream& os, const String& s);

  String(char* str) 
  {
    // size_t => %uz
    sz = strlen(str);
    buff = new char[sz + 1]; // 문자열 + 1 nullptr
    strcpy(buff, str);
  }

  ~String()
  {
    delete[] buff;
  }

  String(const String& str) : sz(str.sz)
  {
    buff = new char[sz + 1];
    strcpy(buff,str.buff);
  }
/*
  String& operator=(const String& s)
  {
    if (this == &s) return;
    sz = s.sz;
    delete[] buff;
    buff = new char[sz + 1];

    strcpy(buff, s.buff);

    return *this;
  }
  */
};

ostream& operator<<(ostream& os, const String& s)
{
  os << s.buff;
  return os;
}

int main()
{
  String s1("hello world"); // String 생성가능
  String s2 = "hello";

  cout << s2 << endl;
  s2 = s2;
  cout << s2 << endl;
  

/*
  cout << s1 << endl; // 출력가능

  String s2(s1); // 복사 생성자

  String s2 = "armkernel"; // 대입연산자

  cout << s1 << s2 << endl;
*/
}
