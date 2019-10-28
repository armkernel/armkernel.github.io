#include <iostream>
#include <cstring>

using namespace std;

class String
{

  char* buff; // 항상 열개? 고정? no => 동적할당으로 가야함
  int size;
  int* ref;
public:
  String () {
    size = 0;
    buff = nullptr;
    ref = new int;
    *ref = 1;
    //cout << "default" << endl;
  }

  String (const char* s)
  {
    size = strlen(s);

    buff = new char[size + 1]; // null 문자 보다 크게
    strcpy(buff, s);
    ref = new int;
    *ref = 1;
  }

  friend std::ostream& operator << (std::ostream& os, 
                               const String& s);
  ~String()
  {
    //cout << "delete" << endl;
    if ( --(*ref) == 0 )
       {
         delete[] buff;
         delete ref;
       }
  }

  String (const String& s) : size(s.size), buff(s.buff), ref(s.ref)
  {
    //cout << "copy" << endl;
    ++(*ref);
    //cout << "copy" << endl;
  }

  String& operator=(const String& s)
  {
    if ( &s == this ) 
      return *this; // 그냥 리턴 => 자신과의 대입을 조사함.

    size = s.size;
    delete[] buff;

    buff = s.buff;
    //buff = new char[size + 1];

    //strcpy(buff, s.buff);
    ref = s.ref;
    ++(*ref);
    return *this;
  }
};

std::ostream& operator<<(std::ostream& os, const String& s)
{
  if (s.buff == nullptr) return os;
  //cout << "cout" << "ref :"<< *s.ref <<endl;
  os << s.buff;
  return os;
}

int main() {
    // 1단계. 생성자, 소멸자, 화면 출력
    String s1 = "hello";
    cout << s1 << endl;
    // 2단계. 복사 생성자
    String s2 = s1;
    cout << s2 << endl;
    // 3단계. 대입연산자
    String s3 = "student";
    s3 = s1;
    cout << s3 << endl;
    // 4단계. 자신과의 대입
    s1 = s1;
    cout << s1 << endl;
    // 5단계. 디폴트 생성자
    String s4;
    cout << s4 << endl;
    //cout << "come" << endl;
}

