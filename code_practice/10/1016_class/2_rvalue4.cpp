#include <iostream>
#include <type_traits>

using namespace std;

// VA_ARGS 가변으로 받은거 다 넣어달라
#define CHECK_VALUE_CATEGORY(...) \
  if ( is_lvalue_reference< decltype((__VA_ARGS__)) >::value ) \
    cout << "lvaue" << endl; \
  else                       \ 
    cout << "rvalue" << endl; 

int main()
{
  // value category를 조사하는 방법

  int n = 0;
  const int c = 10;

  CHECK_VALUE_CATEGORY("hello");
  CHECK_VALUE_CATEGORY(10);
  CHECK_VALUE_CATEGORY(c);

}

