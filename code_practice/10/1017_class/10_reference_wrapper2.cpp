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

// ------------------------------
//
void foo(int& a) { a = 100; }

// bind는 값으로 보관했다가 다시 호출할 때 사용합니다.
template<typename T> void Bind(T arg)
{
  foo(arg);
}

// xreference_wrapper를 만드는 함수
template<typename T>
xreference_wrapper<T> xref(T& obj)
{
  return xreference_wrapper<T>(obj);
}

int main()
{
  int n = 0;
  //Bind(&n); // 주소를 넘기면 됨. 복사했다가 참조로 넘길때, 복사본을 넘기면 안돼 그래서 주소를 넘기자 생각함. 하지만, 주소를 넘기면.. T가 pointer*로 되야해.
  // pointer는 포인터인데.. 참조로 넘길 수 있다면..

//  xreference_wrapper<int> r(n);
//  Bind(r); //결국 주소를 보내는 것, 그런데 r은 int&로 변환가능

  //Bind(xreference_wrapper<int>(n));
  Bind(xref(n));
  cout << n << endl;
}


