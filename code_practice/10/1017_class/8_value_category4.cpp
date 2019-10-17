#include <iostream>
#include <type_traits>

using namespace std;

// VA_ARGS 가변으로 받은거 다 넣어달라
#define CHECK_VALUE_CATEGORY(...) \
  if ( is_lvalue_reference< decltype((__VA_ARGS__)) >::value ) \
    cout << "lvaue" << endl; \
  else if(is_rvalue_reference< decltype((__VA_ARGS__)) >::value)                      \ 
    cout << "rvalue(xvalue)" << endl; \
  else    \
    cout << "rvalue(prvalue)" << endl;

class Point 
{
  public:
    int x,y;
};

// https://en.cppreference.com/w/cpp/language/value_category

int main()
{
  // value category를 조사하는 방법

  int n = 0;
  const int c = 10;

  CHECK_VALUE_CATEGORY("hello");
  CHECK_VALUE_CATEGORY(10);
  CHECK_VALUE_CATEGORY(c);

  Point pt;


  CHECK_VALUE_CATEGORY(pt);
  CHECK_VALUE_CATEGORY(move(pt)); 
  CHECK_VALUE_CATEGORY(Point()); 
  // Point().x = 10;
  // 에러.. 
  // prvalue 에 member data는 뭘까?
  // c++ 표준위원회에서 다름.
  //
  CHECK_VALUE_CATEGORY(Point().x); 


}

