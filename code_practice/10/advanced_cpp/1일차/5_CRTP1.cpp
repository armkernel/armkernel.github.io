// 5_CRTP1.cpp   195 page
#include <iostream>
using namespace std;
// CRTP 를 사용해서 비가상함수를 가상함수처럼 보이게 하는 기술
// MS의 WTL/ATL 등의 라이브러리가 즐겨 사용한 기술.

// 메세지 처리 함수에서만 T를 사용하게 되는 디자인 이다.
// T를 사용하지 않은 모든 함수는 기반 클래스로 옮겨라!!!
// (thin template, template hoisting)
class Window
{
	int handle;
public:
	void moveWindow() {}

	//..... 수십개에 멤버 함수들.
	void LButtonDown() { cout << "Window LButton" << endl; }
};
template<typename T> class MsgWindow : public Window
{
public:
	void msgLoop() // void msgLoop( Window* this)
	{
		// 이벤트 발생을 대기하다가 특정 멤버 함수 호출
		//LButtonDown();  // this->LButtonDown()

		static_cast<T*>(this)->LButtonDown();
	}	
};

class MyWindow2 : public MsgWindow<MyWindow2>
{
public:
	void LButtonDown() { cout << "MyWindow2 LButton" << endl; }
};
class MyWindow : public MsgWindow<MyWindow>
{
public:
	void LButtonDown() { cout << "MyWindow LButton" << endl; }
};
int main()
{
	MyWindow w;
	w.msgLoop(); // msgLoop(&w)
}