#include <iostream>
#include <type_traits>
using namespace std;

template<int N> struct int2type
{
  enum { value = N; }
}

template<typename T> void printv_imp(T v, YES)
{
    cout << v << ":" << *v << endl;
}

template<typename T> void printv_imp(T v, NO)
{
    cout << v << endl;
}


int main()
{
  foo(0);
  foo(1); // 0, 1 은 같은 타입(int), foo(0), foo(1) 은 같은 함수 호출

  int2type<0> t0; // 다른 구조체
  int2type<1> t1; // 다른 타입

  foo(t0);
  foo(t1);
}
