#include <iostream>
#include <functional>

using namespace std;

// C++ 참조: 한번 가리킨 메모리는 변경할 수 없다. 일종의 상수
//          대입 연산시 값이 이동한다.
// reference_wrapper: 이동가능한 참조이다. 대입연산시 참조가 이동
// 

// 결국 " 1. 주소를 보관 " " 2. 진짜 참조타입으로 변환가능 "
template<typename T> struct xreference_wrapper
{
  T* obj;
public:
  // 꼭 참조로 받아야해. 그렇지 않으면 복사본을 가리킴.
  // pointer이다.
  xreference_wrapper(T& r) : obj(&r) {}

  // 진짜 참조와 호환이 되야한다.
  operator T&() { return *obj; }
};



int main()
{
  int n1 = 10;
  int n2 = 20;

//  int& r1 = n1;
//  int& r2 = n2;
//
  xreference_wrapper<int> r1 = n1;
  xreference_wrapper<int> r2 = n2; //얕은 복사이다.
  r1 = r2;
  
  int& r3 = r1;
  // 참조가 이동할것이다?
  // reference는 const? 20이 복사될 것이다?
  // 값이 이동한다.
  // c++참조는 const다. 가리키는 값이 const다.
  // 대입 연산을 하면 const이다.
  // 깊은 복사이다.
  //

  // 결과를 예측해보세요.
  //
  cout << n1 << endl;
  cout << n2 << endl;
  cout << r1 << endl;
  cout << r2 << endl;
}


