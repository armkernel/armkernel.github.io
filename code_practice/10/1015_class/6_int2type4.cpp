#include <iostream>
#include <type_traits>
using namespace std;

template <typename T> void printv(int v)
{

  // 함수 오버로딩에 의한 분기: 컴파일 시간에 이루어진다.
  //  선택되지 않은 함수(template)은 실제 c++ 코드로 생성되지 않는다.
  //
    printv_imp

  /*
  // if문의 조건은 실행할때, 결정됨. 따라서, 컴파일러는 
  // 조사하는 당시 사용할 것 같지 않아도 사용될 수 있다.
  // 실행시간 분기
  // 어디로 갈지 결정하는 방법 ==> 함수 오버로딩
  if (is_pointer<T>::value) 
    printv_pointer(v);
  else
    printv_not_pointer(v);
*/
}

template<typename T> void printv_pointer(T v, YES)
{
    cout << v << ":" << *v << endl;
}

template<typename T> void printv_not_pointer(T v, NO)
{
    cout << v << endl;
}


int main()
{
  int n = 0;
  //printv(n);
  printv(&n);
}
