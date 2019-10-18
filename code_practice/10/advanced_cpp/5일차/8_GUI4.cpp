// 8_GUI1.cpp - g++ ���� �������� �ʽ��ϴ�.   "windows++"
#define USING_GUI
#include <iostream>
#include "cppmaster.h"   // ���� ����(5����) �� ������ ��������
using namespace std;
using namespace cppmaster;

#include <map>

class Window;

map<int, Window*> this_map; 


struct AFX_MSG
{
	int message;				// �޼��� ��ȣ
	void(Window::*handler)();	// �޼����� ó���� �Լ��ּ�
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

	// �Ʒ� �����Լ����� �޼��� ó�� ������ ���� �迭�� ��ȯ�ؾ� �մϴ�.
	virtual AFX_MSG* GetMessageMap()
	{
		return nullptr;
	}

	static int handler(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		if (self == nullptr) return 0;

		// �޼��� ó�� �迭�� ��� �´�.
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
	// WM_KEYDOWN �޼������� OnKeyDown ȣ��ǰ� �غ�����
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