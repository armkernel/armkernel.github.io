#include "menu.hpp"

// 메뉴를 처리하려면, 아래 인터페이스를 정의해야한다. 약속.
struct IMenuListener
{
  virtual void doCommand(int id) = 0;
  virtual ~IMenuListener() {}
};

class MenuItem : public BaseMenu
{
  int id;
  IMenuListener* pListener = 0;
public:

  void setListener(IMenuListener* p) { pListener = p; }

  MenuItem(string s, int n) : BaseMenu(s), id(n) {}

  virtual void command() override
  {
    // 모든 메뉴들이 하는일이 다르니까 가상함수로 만들어서 재정의 한 후 사용하자.
    // 근데 파생클래스가 너무 많아지는 문제가 있음.
    // 파생클래스가 많아지는 문제가 있음
    // 변하는 것을 다른 클래스로 !!
    //  교체가능해야하니깍 인터페이스가 필요함.
    //
    if ( pListener != 0 )
      pListener->doCommand(id);

    // doCommand 입장에서 무조건 일을 하면 안되고 어떤 일을 했는지 조사하고 일을 해야함.
    // Listener방식으로 처리한다면, 리스너가 인자를 받아 처리하도록 한다.
    // 즉, 어떤 메뉴인지 알아야 그 메뉴에 해당하는 걸 부를 수 있다.
    // doCommand는 무조건 일을 하면 안되고 누가 호출했는지 파악해야해.
  }
};

// 방법2. 메뉴 선택시 하는 일을 다른 클래스에 위임한다.
// Java C# 안드로이드 앱 등에서 사용되는 개념
// "Listener" 라는 이름을 사용하는 기술

class Dialog : public IMenuListener
{
public:
  virtual void doCommand(int id)
  {
    // cout << "Dialog doCommand" << endl;
    //
    switch( id )
    {
      case 11: cout << "11" << endl; break;
      case 12: cout << "12" << endl; break;
    }
    // 버튼이 많아 진다면.. switch case 같은 단조로운 코드가 너무 커진다. 그래서 다른 방법을 사용해야함 
  }
};



int main()
{
  Dialog dlg;
  MenuItem m1("Add Student", 11);
  MenuItem m2("Remove Student", 12);

  m1.setListener(&dlg);
  m2.setListener(&dlg);

  m1.command();
  m2.command();
}
