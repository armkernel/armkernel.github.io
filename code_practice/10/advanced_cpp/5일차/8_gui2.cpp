// 8_GUI1.cpp - g++ ���� �������� �ʽ��ϴ�.   "windows++"
#define USING_GUI
#include <iostream>
#include "cppmaster.h"   // ���� ����(5����) �� ������ ��������
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

	// �ٽ� 1. C�� callback �Լ�(������ ������ ��Ģ���� ������ �ִ�)��
	//			C++ ����� ���鶧�� �ݵ�� static ���� �ؾ� �Ѵ�.
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
	w.Create("A"); // ������ ����

	ec_process_message(); 
}