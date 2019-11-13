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

  virtual void command() = 0; // !! 핵심 부분
};

class MenuItem : public BaseMenu
{
  int id; // 선택했을 때 일해야함.
public:
  //MenuItem(int n) : id(n) {}
  MenuItem(string s, int n) : BaseMenu(s), id(n) {}

  virtual void command() override
  {
    cout << getTitle() << endl;
    getchar(); // 잠시 대기
  }
};


int main()
{
  // MenuItem m(11); // error.
  // 파생 클래스를 만들 경우 기반클래스 생성자를 불러야함. 근데 구현이 안되있음.. 그럼 에러 
  // 기반 클래스의 디폴트 생성자가 없다면.. 파생클래스에서 기반클래스를 부르는 코드를 만들어줘야함.

  MenuItem("sound", 11);

}
