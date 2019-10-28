// 8_GUI1.cpp - g++ 에서 동작하지 않습니다.   "windows++"
#define USING_GUI
#include <iostream>
#include "cppmaster.h"   // 현재 폴더(5일차) 에 복사해 놓으세요
using namespace std;
using namespace cppmaster;

int handler(int hwnd, int msg, int a, int b)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: cout << hwnd << " LBUTTON" << endl; break;
	case WM_KEYDOWN:     cout << hwnd << " KEYDOWN" << endl; break;
	}
	return 0;
}
int main()
{
	int h1 = ec_make_window(&handler, "A");
	int h2 = ec_make_window(&handler, "B");

	ec_process_message(); // 종료 되지 말고 메세지를 처리해달라
						  // win32 api 메세지 루프
}