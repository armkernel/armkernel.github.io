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

// popup menu만들기 핵심

class PopupMenu : public BaseMenu
{
  //vector<MenuItem*> v; // 핵심.. MenuItem받으면 안돼..
  vector<BaseMenu*> v;
public:
  PopupMenu( string s ) : BaseMenu(s) {}

  void addMenu(BaseMenu* p) { v.push_back(p); }
  // 핵심.. 무조건 upstream으로 가야함.

  // 메뉴 아이템 같은 경우 선택됐을 때, 어떤 일을 하면되는데.. popup menu는 뭘해야하나?  선택했을 때, 어떤 일을 하는 것이 아니라 하위를 열어야함.
  virtual void command() override
  {
    // 일을 한번만 하고 딱 끝나는게 아니라 계속해서 돌아야함. 그래서 무한루프를 돌아야함.
    // 그냥 c같지 않나? 노우.. 사용자 코드를 보면 다르다.
    while(1) {
      system("cls"); // 깨끗하게 지워줌

      int sz = v.size(); // 개수 꺼내고

      for (int i = 0; i < sz; i++) 
      {
        cout << i + 1 << ". " << v[i]->getTitle() << endl;
      }

      cout << sz + 1 << ". 상위메뉴로" << endl;
      // 여기까지가 화면에 메뉴 출력 
      //
      int cmd;

      cout << "메뉴를 선택하세요 >> ";
      cin >> cmd;

      if ( cmd < 1 || cmd > sz + 1 ) // 예외처리.. 잘못된 입력 
        continue;
      
      if (cmd == sz + 1) break;

      // 선택된 메뉴 실행 <- 이 부분이 핵심
      // 메뉴 아이템이면 일을 하면되고 팝업이면 하위 출력.. 조사할 필요가 없다.
      // 다형성!! 핵심
      v[cmd - 1]->command(); // 기반 클래스에서는 할게 없음.. 니네가 알아서 짜라.. 그렇다면 밑에서 쓸 수 없다. 기반 클래스 포인터이기 때문에 command가 없으면 컴파일 에러.. 아무리 base에서 command가 제공할 일이 없다라도 모든 파생클래스의 공통 규칙이라면 묶는게 좋다.
    }
  }
};

int main()
{
  PopupMenu pm("화면 설정");
}
