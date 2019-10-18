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

	virtual AFX_MSG* GetMessageMap()
	{
		return nullptr;
	}

	static int handler(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		if (self == nullptr) return 0;

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

#define DECLARE_MESSAGE_MAP(classname)			\
				virtual AFX_MSG* GetMessageMap();

#define BEGIN_MESSAGE_MAP(classname)			\
	AFX_MSG* classname::GetMessageMap()			\
	{											\
		typedef void(Window::*HANDLER)();		\
		static AFX_MSG arr[] = {				

#define ADD_MESSAGE(message, handler)			\
			{message, (HANDLER)handler},

#define END_MESSAGE_MAP()				\
			{0, 0}						\
		};								\
		return arr;						\
		}

// www.google.com 에서 wxWidget event table 검색해 보세요
// C++ gui 라이브러리 : nana    

// Form form;
// form.lbutton = [&form]() { cout << "hello" << endl;form.close() };
// form.keydown = 

class Frame : public Window
{
public:
	DECLARE_MESSAGE_MAP(Frame)
	void OnLButtonDown() { cout << "Frame LBUTTON" << endl; }
	void OnKeyDown() { cout << "Frame KEYDOWN" << endl; }
};

BEGIN_MESSAGE_MAP(Frame)
	ADD_MESSAGE(WM_LBUTTONDOWN, &Frame::OnLButtonDown)
	ADD_MESSAGE(WM_KEYDOWN, &Frame::OnKeyDown)
END_MESSAGE_MAP()



int main()
{
	Frame w;
	w.Create("A");

	ec_process_message();
}