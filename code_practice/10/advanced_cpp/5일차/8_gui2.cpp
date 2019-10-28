// 8_GUI1.cpp - g++ 에서 동작하지 않습니다.   "windows++"
#define USING_GUI
#include <iostream>
#include "cppmaster.h"   // 현재 폴더(5일차) 에 복사해 놓으세요
using namespace std;
using namespace cppmaster;



class Window
{
	int handle;
public:
	void Create(string title)
	{
		handle = ec_make_window(&handler, title);
	}

	// 핵심 1. C의 callback 함수(인자의 갯수가 규칙으로 정해져 있다)를
	//			C++ 멤버로 만들때는 반드시 static 으로 해야 한다.
	static int handler(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: cout << hwnd << " LBUTTON" << endl; break;
		case WM_KEYDOWN:     cout << hwnd << " KEYDOWN" << endl; break;
		}
		return 0;
	}
};

int main()
{
	Window w;
	w.Create("A"); // 윈도우 생성

	ec_process_message(); 
}