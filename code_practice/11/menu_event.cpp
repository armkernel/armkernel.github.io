#include "menu.hpp"

class MenuItem : public BaseMenu
{
  int id;
public:
  MenuItem(string s, int n) : BaseMenu(s), id(n) {}

  virtual void command() override
  {
    // 여기서 하는 일은 메뉴 일을 하는게 아니라 해당 일에 관련된 함수를 호출하도록 해야지.. 메뉴마다 기능이 다름.
    // 변하는 부분이 있으면 가상함수로 뽑아야해.
    // 어떤 일을 직접하지말고 함수를 부르자.
    doCommand();
  }

  virtual void doCommand(){}; // 이걸 사용하는 의도는 이걸 사용하지말고 파생클래스를 만들어라.
};

class AddStudentMenu : public MenuItem
{
public:
  using MenuItem::MenuItem; // 생성자 상속..
  // 기반클래스에 있으니 그거 써달라.
  virtual void doCommand() { cout << "Add Student" << endl; }  
};

class RemoveStudentMenu : public MenuItem
{
public:
  using MenuItem::MenuItem;
  virtual void doCommand() { cout << "Remove Student" << endl; }  
};

int main()
{
  AddStudentMenu m1("Add Student", 11);
  RemoveStudentMenu m2("Remove Student", 12);

  // 어떤 일을 해야한다.
  // 우리는 타이틀 출력만 하는 걸 출력함
  // 여기서 진짜 일을 해야함.
  // 메뉴를 선택할 때, 하는 일은 메뉴 객체에 따라 다르다.
  m1.command();
  m2.command();
}
