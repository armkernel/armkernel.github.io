#include <iostream>
#include <functional>

using namespace std;

void foo() { cout << "foo" << endl; }

class Dialog
{
public:
  void Close() { cout << "Dialog Close" << endl; }
};

int main()
{
  // IAction을 만들 필요 없이,
  // C++11 부터 지원되는 일반화된 함수포인터 역할을 하는 function template을 이용하면 됨.
  // 헤더파일은 <functional>이 필요함
  function
  void(*f1)()   = &foo;
  void(Dialog::*f2) = &Dialog::Close;
}

