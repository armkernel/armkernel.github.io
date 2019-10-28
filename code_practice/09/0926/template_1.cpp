#include <iostream>

using namespace std;

template<typename T>
class foo 
{
  int a;
public:
  T general() const;
  static int cnt;
  template<typename U> T func(const U& c); // 클래스 내 멤버함수 template 일 경우..
  foo(T a) {}
};

template<typename T> int foo<T>::cnt = 0;
int cnt = 1;

template<typename T> T foo<T>::general() const
{
}

int main()
{
  foo f(10);
  f.cnt++;

  cout << f.cnt << endl;
  cout << cnt << endl;
}
