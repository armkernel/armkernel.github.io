#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void printv(T v)
{
  // C++17에서 나오는 정적 if 문
  // template에서 조건을 만족하지 않으면 코드를 생성하지 않는다.
  if constexpr (is_pointer<T>::value) // if(false) 이 경우.. 
                            // 실행할 때는 문제가 안됨. 컴파일 할 경우 문제가됨.
    cout << v << ":" << *v << endl;
  else
    cout << v << endl;
}


void printv(int v)
{
  // C++17에서 나오는 정적 if 문
  // template에서 조건을 만족하지 않으면 코드를 생성하지 않는다.
  if constexpr (is_pointer<T>::value) // if(false) 이 경우.. 
                            // 실행할 때는 문제가 안됨. 컴파일 할 경우 문제가됨.
    // cout << v << ":" << *v << endl; 만약 false라면 아래의 코드를 지워버림.
    // compile time 조건문
    // if define을 가지고 T 값을 알 수가 없음.

  else
    cout << v << endl;
}

int main()
{
  int n = 0;
  printv(n);
  //printv(&n);
}
