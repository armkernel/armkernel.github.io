#include <iostream>
#include <string>
#include <vector>
using namespace std;

// composite pattern 을 활용한 메뉴 만들기
// GUI 보면 메뉴가 있음
//  C로 만들었을 때 참조.. 옵션같은 경우 일을 함  MenuItem... profile같은 경우 하위 메뉴를 열어줌 -> PopUpMenu
//
//  그림을 그려보자
//
//
//  PopupMenu  MenuItem
//  vector<MenuItem*> <- 이렇게 담으면.. MenuItem만 담을 수 있다.. 만약 PopupMenu 가 있다면..? 이러면 담을 수 없다.. upstream했을 때 공통적인 것은 하나의 기반클래스로 묶어서 관리해야한다는 거 생각해야함
//
//  다시 그려보면
//  BaseMenu   string title;
//             command() = 0; // 일을 한다. 핵심이 커맨드..
//      / \
//  PopupMenu MenuItem int id; -> 일을 해야함.
//  addMenu(BaseMenu*);
//
//  vector<BaseMenu*>
//
//  객체지향 할때, 몇가지 생각해야하는 핵심
//  1. 공통적인건 묶어
//  2. 변하는 것과 변하지 않는 건 분


int main()
{

}
