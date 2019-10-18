// 8_GUI1.cpp - g++ 에서 동작하지 않습니다.   "windows++"
#define USING_GUI
#include <iostream>
#include "cppmaster.h"   // 현재 폴더(5일차) 에 복사해 놓으세요
using namespace std;
using namespace cppmaster;

#include <map>

class Window;

map<int, Window*> this_map; 


struct AFX_MSG
{
	int message;				// 메세지 번호
	void(Window::*handler)();	// 메세지를 처리할 함수주소
};




class Window
{
	int handle;
public:
	void Create(string title)
	{
		handle = ec_make_window(&handler, title);
		this_map[handle] = this;
	}

	// 아래 가상함수에서 메세지 처리 정보를 담은 배열을 반환해야 합니다.
	virtual AFX_MSG* GetMessageMap()
	{
		return nullptr;
	}

	static int handler(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		if (self == nullptr) return 0;

		// 메세지 처리 배열을 얻어 온다.
		AFX_MSG* arr = self->GetMessageMap();

		if (arr == nullptr) return 0;

		while (arr->message != 0)
		{
			if (arr->message == msg)
			{
				void(Window::*f)() = arr->handler;

				(self->*f)();
			}
			++arr;
		}

		return 0;
	}
};

class Frame : public Window
{
public:
	// WM_KEYDOWN 메세지에서 OnKeyDown 호출되게 해보세요
	virtual AFX_MSG* GetMessageMap()
	{
		typedef void(Window::*HANDLER)();

		static AFX_MSG arr[] = {
			{WM_LBUTTONDOWN, (HANDLER)&Frame::OnLButtonDown},
			{WM_KEYDOWN, (HANDLER)&Frame::OnKeyDown},
			{0, 0}
		};
		return arr;
	}
	void OnLButtonDown() { cout << "Frame LBUTTON" << endl; }
	void OnKeyDown()     { cout << "Frame KEYDOWN" << endl; }
};

int main()
{
	Frame w;
	w.Create("A");

	ec_process_message();
}