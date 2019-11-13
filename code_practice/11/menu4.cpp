#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BaseMenu
{
  string title;
public:
  BaseMenu( string s) : title(s) {}
  string getTitle() const { return title; }
  virtual void command() = 0; 
};

class MenuItem : public BaseMenu
{
  int id;
public:
  MenuItem(string s, int n) : BaseMenu(s), id(n) {}

  virtual void command() override
  {
    cout << getTitle() << endl;
    getchar(); 
  }
};

class PopupMenu : public BaseMenu
{
  vector<BaseMenu*> v;

public:
  PopupMenu( string s ) : BaseMenu(s) {}

  void addMenu(BaseMenu* p) { v.push_back(p); }
  virtual void command() override
  {
    while(1) {
      // system("cls"); 
      system("clear"); // mac용  
      int sz = v.size(); 
      for (int i = 0; i < sz; i++) 
      {
        cout << i + 1 << ". " << v[i]->getTitle() << endl;
      }

      cout << sz + 1 << ". 상위메뉴로" << endl;
      int cmd;

      cout << "메뉴를 선택하세요 >> ";
      cin >> cmd;

      if ( cmd < 1 || cmd > sz + 1 )
        continue;
      
      if (cmd == sz + 1) break;
      v[cmd - 1]->command(); 
    }
  }
};

int main()
{
  // 복합객체 (composite, node) 라고 부름
  PopupMenu* menubar = new PopupMenu("MenuBar");
  PopupMenu* pm1 = new PopupMenu("화면 설정");
  PopupMenu* pm2 = new PopupMenu("소리 설정");
  MenuItem* m1 = new MenuItem("정보 확인", 11);

  menubar->addMenu(pm1);
  menubar->addMenu(pm2);
  menubar->addMenu(m1);

  pm1-> addMenu( new MenuItem ("해상도 변경",21));
  pm1-> addMenu( new MenuItem ("명암 변경",22));
 
  // leaf이라고 부름.
  pm2-> addMenu( new MenuItem ( "음량 조절",31));
  // 시작하려면
  menubar->command();

  // Composite 패턴
  // 객체들을 트리 구조로 구성하여 부분과 전체를 나타내는 계층 구조로 만드는 것을 말함
  // 개별 객체와 복합객체를 구별하지 않고 동일한 방법으로 다룰 수 있게 함
  // 재귀적인 느낌이 난다. 파업이 파업을 부름.

  // C로 구현하기 위해서는 메뉴 변경하는 부분 메뉴 추가하는 부분들 다양하게 변경되야한다. C++ 은 한줄만 추가하면 된다. 어떤 메뉴를 그냥 추가만 하면 됨
}
