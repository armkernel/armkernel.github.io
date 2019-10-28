// 9_평가되지 않는 표현식. - 143page
//

#include <iostream>
using namespace std;

int foo(int a)
{
  cout << "foo" << endl;
  return 0;
}

int main()
{
  int n = 0;
  cout << sizeof(n)       << endl; // 4byte
  cout << sizeof(&foo)    << endl; // function address : 4byte or 8byte
  // cout << sizeof(foo)     << endl; // error. 함수의 크기를 구할 수 없다.
                                   // 함수의 주소가 필요한 곳에서는 암시적 형변환이 됨.
  cout << sizeof(foo(0))  << endl; // 함수를 호출했을 때, 반환값의 크기. 
                                   // 함수를 호출하는 수식을 썼는데.. 함수를 호출하는 것이 아니라 컴파일러가 반환값 확인 후 찾아준다.
                                   //
                                   //
  sizeof(foo(0));

  decltype(foo(0)) n2;
  //const type_info& = typeid(foo(0));
  bool b = noexcept(foo(0));

  // unevaluated expression (평가되지 않은 표현식)
  // 함수 호출식이 실제로 함수를 호출하지 않는 것. 4개
  //
  // 1. sizeof(foo(0)); //반환값의 크기 4
  //  - 함수 호출 했을 때, 나오는 크기
  // 2. decltype(foo(0)) n; 반환값과 동일 타입
  //  - int type
  // 3. const type_info& = typeid(foo(0));
  //  - 호출 했을 때, 타입에 대한 정보.
  // 4. bool b = noexcept( foo(0) );
  //  - 예외가 있을 것 같으면 true아니면 false
  //
  // 예외의 가능성이 없다면 noexcept라고 적어야함
  //
  //
   
}
