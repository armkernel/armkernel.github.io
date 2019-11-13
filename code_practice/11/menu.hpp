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
  {
    return 0; 
  }

  virtual void addMenu(BaseMenu* p)
  {
    throw "unsupported function";
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
