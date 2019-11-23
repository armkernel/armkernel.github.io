#include <iostream>

using namespace std;

void foo() { cout << "foo" << endl; }

class Dialog
{
public:
  void Close() { cout << "Dialog Close" << endl; }
};

struct IAction
{
  virtual void Execute() = 0;
  virtual ~IAction() {}
};

// 이 친구가 하는 일은 함수포인터 호출해주는 역할
class FunctionAction : public IAction
{
  typedef void(*FP)();

  FP handler;
public:
  FunctionAction(FP f) : handler(f) {}
  // FunctionAction 내부적으로 함수의 포인터 가지고있다가, 생성자로 초기화 해주고 필요할 때, 실행하면 됨.
  virtual void Execute() { handler(); }
};

template<typename T>
class MemberAction : public IAction
{
  typedef void(T::*FP)();

  FP handler;
  T* target;
public:
  MemberAction(FP f, T* obj) : handler(f), target(obj) {}
  virtual void Execute() { (target->*handler)(); }
};

int main()
{
  // void(*f1)()   = &foo;
  //
  Dialog dlg;
  IAction* p1 = new FunctionAction(&foo);
  IAction* p2 = new MemberAction<Dialog>(&Dialog::Close, &dlg);
  p1->Execute(); // 이순간 실행은 foo();
  p2->Execute(); // 이순간 실행은 foo();


  // 일반함수포인터 실행. 
  //void(Dialog::*f2) = &Dialog::Close;
  // 일반함수 뿐만아니라 멤버함수를 실행. 그렇다면, 모든 타입을 다 받아야한다. -> Template으로 가야함.
}
