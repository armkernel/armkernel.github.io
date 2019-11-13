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
  virtual BaseMenu* getSubMenu(int idx) 
  // =0; //이렇게 짜지마라. 순수 가상함수는 무조건 해야하니까.
  {
    // throw "unsupported function"
    return 0; // 실패를 리턴하도록 해야해. -1, 0 이런 식으로 
  }

  virtual void addMenu(BaseMenu* p)
  {
    throw "unsupported function";
  }
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

  virtual void addMenu(BaseMenu* p) override { v.push_back(p); }
  virtual void command() override
  {
    while(1) {
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

  virtual BaseMenu* getSubMenu(int idx) override
  {
    return v[idx];
  }
    
};

int main()
{
  PopupMenu* menubar = new PopupMenu("MenuBar");
  PopupMenu* pm1 = new PopupMenu("화면 설정");
  PopupMenu* pm2 = new PopupMenu("소리 설정");
  MenuItem* m1 = new MenuItem("정보 확인", 11);
  menubar->addMenu(pm1);
  menubar->addMenu(pm2);
  menubar->addMenu(m1);
  pm1-> addMenu( new MenuItem ("해상도 변경",21));
  pm1-> addMenu( new MenuItem ("명암 변경",22));
  pm2-> addMenu( new MenuItem ( "음량 조절",31));

  // 하위 메뉴를 얻는 getSubMenu() 추가
  BaseMenu* p =menubar->getSubMenu(1)->getSubMenu(0);
 // 결국 이렇게 해서 음량 조절을 얻고 싶은 것이다.
 // menubar->getSubMenu(1) 여기 반환하는건 baseMenu인데.. BaseMenu내에는 submenu를 얻는 함수가 없다.
 // -> getSubMenu를 파생에만 넣을 것이냐 기반 클래스에도 넣을 것이냐? 결정 
 // 결국 쓰게 하려면 넣어줘야함. 베이스에..

  // 이렇게도 사용이 가능하게 하려면...
  menubar -> getSubMenu(1) -> addMenu( new MenuItem("aa", 100) );
  // 우리가 팝업 추가가 popup menu에서만 필요할 것 같아서 해당 클래스에만 넣어뒀다 .하지만.. 사용해보니 필요하더라.. 그럼 유연하게 하기 위해서 베이스에 넣어둬야함

  menubar->command();
}
