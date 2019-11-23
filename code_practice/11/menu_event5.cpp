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

class FunctionAction : public IAction
{
  typedef void(*FP)();

  FP handler;
public:
  FunctionAction(FP f) : handler(f) {}
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

template<typename T> 
MemberAction<T>* action( void(T::*f)(), T* obj)
{
  return new MemberAction<T>( f,obj );
}

FunctionAction* action( void(*f)())
{
  return new FunctionAction( f );
}

int main()
{
  // void(*f1)()   = &foo;
  //
  Dialog dlg;
  //IAction* p1 = new FunctionAction(&foo);
  //IAction* p2 = new MemberAction<Dialog>(&Dialog::Close, &dlg);
  // 위의 것은 추론이 가능한데.. 이게 클래스 템플릿이라서 타입 생략이 불가능하다. 
  // !!! 이 친구는 클래스 템플릿을 생성하는 함수 템플릿을 도움함수로 만들면 편리함. 
  // 무슨 소리인가?
  //
  IAction* p1 = action(&foo);
  IAction* p2 = action(&Dialog::Close, &dlg);
  // 거의 동일한 모양이 된다.
  //

  // dialog 보고 타입 추론이 가능해짐.
  // 한번 더 랩핑을 함. 
  // 함수가 클래스 템플릿이 아니라 함수 템플릿이다.
  // 일반함수와 멤버함수를 담을 수 있는 클래스를 만듬. 예전에는 많이 작성함. C++11 부터는 도입됐다. 이런 개념을 가지고 만들어진 개념이 있다.

  p1->Execute(); // 이순간 실행은 foo();
  p2->Execute(); // 이순간 실행은 foo();
}

// 앞에서 만든 template 코드를 사용하기 쉽도록 변경



/*
template<typename T> void square(T a) { return a*a; }

square(3);
square<int>(3);

list<int> s(10,3);
*/
// 함수 템플릿은 타입을 명시적으로 지정하지 않아도 컴파일러가 함수의 인자를 통해 타입이 추론 가능하다.
//
//
// 클래스 템플릿.
// C++에는 타입을 생략할 수 없다. C++17부터는 생략이 가능함.
// 명시적으로 전달해야한다.
