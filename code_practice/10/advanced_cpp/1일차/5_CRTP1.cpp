// 5_CRTP1.cpp   195 page
#include <iostream>
using namespace std;
// CRTP �� ����ؼ� �񰡻��Լ��� �����Լ�ó�� ���̰� �ϴ� ���
// MS�� WTL/ATL ���� ���̺귯���� ��� ����� ���.

// �޼��� ó�� �Լ������� T�� ����ϰ� �Ǵ� ������ �̴�.
// T�� ������� ���� ��� �Լ��� ��� Ŭ������ �Űܶ�!!!
// (thin template, template hoisting)
class Window
{
	int handle;
public:
	void moveWindow() {}

	//..... ���ʰ��� ��� �Լ���.
	void LButtonDown() { cout << "Window LButton" << endl; }
};
template<typename T> class MsgWindow : public Window
{
public:
	void msgLoop() // void msgLoop( Window* this)
	{
		// �̺�Ʈ �߻��� ����ϴٰ� Ư�� ��� �Լ� ȣ��
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