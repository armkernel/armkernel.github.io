#include <iostream>
#include <type_traits>
using namespace std;

template <typename T> void printv(int v)
{
  if (is_pointer<T>::value) 
    printv_pointer(v);
  else
    printv_not_pointer(v);
}
// if 문일 경우 -> 실행 시 조사.

// pointer와 pointer가 아닌 경우에 대해 같이 놓지마라.
//  => 분리해라.

template<typename T> void printv_pointer(T v)
{
    cout << v << ":" << *v << endl;
}

template<typename T> void printv_not_pointer(T v)
{
    cout << v << endl;
}


int main()
{
  int n = 0;
  //printv(n);
  printv(&n);
}
