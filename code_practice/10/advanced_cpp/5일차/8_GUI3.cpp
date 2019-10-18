// 8_GUI1.cpp - g++ 에서 동작하지 않습니다.   "windows++"
#define USING_GUI
#include <iostream>
#include "cppmaster.h"   // 현재 폴더(5일차) 에 복사해 놓으세요
using namespace std;
using namespace cppmaster;

#include <map>

class Window;

map<int, Window*> this_map; // 또는 핸들 맵 이라도 부르는 개념입니다.
							// 대부분의 GUI 라이브러리에 이 개념이 있습니다.
class Window
{
	int handle;
public:
	void Create(string title)
	{
		handle = ec_make_window(&handler, title);
		this_map[handle] = this;
	}
	static int handler(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		// 이제 self 가 this입니다.
		switch (msg)
		{
		case WM_LBUTTONDOWN: self->OnLButtonDown(); break;
		case WM_KEYDOWN:     self->OnKeyDown();     break;
		}
		return 0;
	}

	virtual void OnLButtonDown() {}
	virtual void OnKeyDown() {}
};

class Frame : public Window
{
public:
	virtual void OnLButtonDown() { cout << "Frame LBUTTON" << endl; }
};

int main()
{
	Frame w;
	w.Create("A"); 

	ec_process_message();
}