// forwarding reference 는 어떤 의미가 있는가?
//
// 모든 정수 값을 받을 수 있는 함수를 만들고 싶다.

// 방법 1. call by value
// 특징 : 복사본 생성, 크기가 큰 타입의 경우 오버헤드가 있음.
// void foo(int arg) {}

// 방법 2. call by reference
// 특징 : lvalue 만 가능
// void foo(int& arg) {}

// 방법 3. call by reference
// 특징 : lvalue, rvalue 다 받을 수 있다. 원본 메모리 수정 불가능.
// void foo(const int& arg) {}

// 방법 4. 함수 2개를 만든다.
// 특징 : 원본에 const를 추가하지 않고 그대로 받을 수 있다.
//      단, 2개의 함수를 만들어야한다.
// void foo(int& arg) {}
// void foo(int&& arg) {}

#include <iostream>
using namespace std;

// 방법 5. forwarding reference 를 사용하면
//        자동으로 위의 2개 함수가 생성된다.
template<typename T> void foo(T&& arg)
{
  // 모든 걸 만들어줌.
  cout << __PRETTY_FUNCTION__ << endl;
}

int main()
{
  int n = 10;
  foo(n); //  T: int&        arg: int&
  foo(10); // T: int         arg: int&&
}
