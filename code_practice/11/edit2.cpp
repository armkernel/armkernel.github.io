#include <iostream>
#include <string>
//#include <ctype.h>

#include <termios.h>
#include <unistd.h>
//#include <cstdio>
#include <curses.h>
// #include <conio.h>
using namespace std;


// getch 는 linux나 mac에서 사용할 수 없으므로
// 구현해야한다.
// #include <conio.h> getchar() linux는 없어
/*
int getch(void)
{
  struct termios oldt, newt;
  int ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO);

  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}
*/
class Edit
{
  string data;
public:
  string getData()
  {  
    // cin >> data;
    data.clear();
    while(1)
    {
      char c = getchar();
  
      if(c == '\n') break;

      if(isdigit(c)) {
        cout << c;
        data.push_back(c);
      }
    }
    cout << endl;

    return data;
  }
};

// 이름이 아닌 나이를 입력받는다고 해보자.
// GetData의 정책을 이름이 아닌 나이를 받도록 한다고 가정해보자.
// 나이같은 경우 숫자만 입력받도록 해야한다.

int main()
{
  Edit edit;

  while(1)
  {
    // string str = edit.getData();
    char c = getch();
    cout << c << endl;
    //cout << str << endl;
  }
}
