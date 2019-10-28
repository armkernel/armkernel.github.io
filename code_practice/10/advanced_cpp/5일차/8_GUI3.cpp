// 8_GUI1.cpp - g++ ���� �������� �ʽ��ϴ�.   "windows++"
#define USING_GUI
#include <iostream>
#include "cppmaster.h"   // ���� ����(5����) �� ������ ��������
using namespace std;
using namespace cppmaster;

#include <map>

class Window;

map<int, Window*> this_map; // �Ǵ� �ڵ� �� �̶� �θ��� �����Դϴ�.
							// ��κ��� GUI ���̺귯���� �� ������ �ֽ��ϴ�.
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

		// ���� self �� this�Դϴ�.
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