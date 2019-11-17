#include <iostream>

using namespace std;

void foo() { cout << "foo" << endl; }

class Dialog
{
public:
  void Close() { cout << "Dialog Close" << endl; }
};

int main()
{
  void(*f1)()   = &foo;
  void(Dialog::*f2) = &Dialog::Close;
}

// 일반함수와 멤버함수를 담을 수 있는 함수 포인터를 만들어보자.
//
// 일반함수 포인터에다 클래스 이름을 적으면 멤버함수를 담을 수 있다.


// 그림을 그려보자
//
//
// 두개의 타입이 다름 클래스로 wrapping
//  => 둘을 묶어서 관리하고 싶다면, 공통의 기반 클래스가 있으면 됨.
// 
//            IAction 
//            순수가상함수    execute = 0;
//        /           \
// &foo               &Dialog::Close
// 일반함수 포인터   멤버함수 포인터
// FunctionAction     MemberAction
