#include "menu.hpp"


class MenuItem : public BaseMenu
{
  int id;

  void (Dialog::*handler)();
  // 이렇게 정의할 경우 이자리에는 일반함수만 올 수 있다. 즉, Dialog는 올 수 없다. 
  //
  // Dialog 호출하기 위해서는 객체도 있어야함.
  Dialog* target;
  // 이렇게 모양을 잡으면 다른 클래스의 모양을 받을 수 없다. 모든 타입을 받으려면.. template으로 가야함. 코드가 복잡해질 수도 있다.
  //
  // 일반함수와 멤버함수를 동시에 담을 수 있는 함수의 포인터가 없다.
  //
  // 범용적인 함수 포인터 하나만 있다면 편할 텐데.. 
  // C# delegator .. objective c -> selector
  //
  // c++ 에서는 간단한 객체 지향 테크닉을 이용하면 범용적인 함수 포인터를 사용할 수 있음
public:
  void setHandlerr( void(*f)()) { handler = f; }

  MenuItem(string s, int n) : BaseMenu(s), id(n) {}

  virtual void command() override
  {
    // 인터페이스 만들지말고.. 그냥 함수 받아보자.
    handler();
  }
};

class Dialog : public IMenuListener
{
public:
  virtual void doCommand(int id)
  {
    switch( id )
    {
      case 11: cout << "11" << endl; break;
      case 12: cout << "12" << endl; break;
    }
  }
};

int main()
{
  Dialog dlg;
  MenuItem m1("Add Student", 11);
  MenuItem m2("Remove Student", 12);

  m1.setListener(&dlg);
  m2.setListener(&dlg);
  // 이 메뉴를 선택했을 때, 이 객체를 이용해서 처리하겠다. 메뉴를 선택했을 때, 함수를 호출 할 것이면.. 함수를 넘기면 되는데.. 객체를 넘김. 이렇게 하는 이유가.. 이미 함수에 대한 정보는 인터페이스에 규약으로 적혀져있다. 그래서 객체에 대한 정보를 넘기면 어떤일을 할 수 있을지 안다. 객체만 연결해주면 doCommand가 잘 연결됨. 함수 이름이 이미 약속되어져있기 때문에 doCommand로 연결 되어짐. 그래서 이 함수 안에서 어떤 함수가 요청되었는지 조사를 해야함.
  //
  // 이렇게 하지말고.. 메뉴가 있고 다이얼로그가 있을 때, 함수를 일반적인 인자로 연결하는건 어떨까? 즉, 메뉴가 객체가 아닌 함수와 연결하는건 어떨까

  m1.command();
  m2.command();
}
