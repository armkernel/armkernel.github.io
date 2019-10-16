// 8_forwarding_reference - 아주 중요하다. C++11 의 핵심기술

// int& : int타입에 lvalue만 받을 수 있다.
// int&& : int 타입에 rvalue만 받을 수 있다.
// T&   : 임의의 타입의 lvalue만 받을 수 있다.
// T&&  : 임의의 타입의 lvalue와 rvalue를 모두 받을 수 있다.
//  (forwarding reference..)
//  (universal reference.. - effective c++ 저자)

// 인자로 n(lvalue)를 보내면 T : int&   T&& a : int&
// 인자로 10(rvalue)를 보내면 T : int   T&& a : int&&

// 결국, f4(int&)와 f4(int&&) 함수를 생성한다는 것!

void f1(int& ) {}
void f2(int&&) {}

template<typename T> void f3(T& a)  {}

int main()
{
  int n = 0;

  // 1. 사용자가 타입을 명시적으로 지정하는 경우
  f3<int>(n);   // T& : int& f3(int& a) 인 함수 생성 .. 10보내면 error. 만들어진 타입이 lvaule.
  f3<int&>(n);  // T& : int& & -> collapsing -> int& 
  f3<int&&>(n); // T& : int&& & -> collaping -> int & 

  // 2. 사용자가 타입을 지정하지 않은 경우 - 대부분 이렇게 사용ㅇ
  // 함수 인자를 보고 컴파일러가 T 타입을 결정해야 한다.
  // 우리는 이렇게 씀.
  f3(n); // T는 다 사용가능 -> 가장 단순한 거 사용함 int

  f3(10); // compile error. int로 할 수 있는 경우의 수 다 해보고 에러 발생함.
}
template<typename T> void f4(T&& a) {}

int main()
{
  int n = 0;

  // 1. 타입을 명시적으로 전달하는 경우 => 사용자가 어떤 함수를 생성할지 결정하는 것
  f4<int>(10);    // T&& : int&&      f4(int&& a) 생성
  f4<int&>(n);   // T&& :  int& && ->  collapsing    f4(int& a) 생성
  f4<int&&>(10);  // T&& :  int&& && -> &&     f4(int&& a) 생성

  // 2. 타입을 전달하지 않으면 컴파일러가 인자를 보고 타입을 결정해야한다.
  f4(n); // lvalue를 받을 수 있는 건 T -> int& 밖에 없음 
         // T : int&, T&& : int& : int& && => int&  a의 타입 : int&
  f4(10); // T는 int  T&& : int && -> int && a의 타입 : int&&

  // l,r 둘다 빨아드림. 속성의 변화 없이 모든 종류의 속성을 다 빨아드림.
}
