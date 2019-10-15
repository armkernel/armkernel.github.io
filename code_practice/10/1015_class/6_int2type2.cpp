#include <iostream>
#include <type_traits>
using namespace std;

/*
template<typename T> void printv(T v)
{
  // printv(int v).. error. 
  
  if (is_pointer_v<T>)  // is_pointer::value 가 포인터라면..
    cout << v << ":" << *v << endl;
  else
    cout << v << endl;
}*/

// printv(n)으로 사용하면 아래의 코드가 생성됨.
// false 부분이라도 template의 경우 다시 코드를 만들고 compile check를 한다.
// 따라서, 오류남.
//
void printv(int v)
{
  if (false)  // is_pointer::value 가 포인터라면..
    cout << v << ":" << *v << endl;
  else
    cout << v << endl;
}

int main()
{
  int n = 0;
  //printv(n);
  printv(&n);
}
