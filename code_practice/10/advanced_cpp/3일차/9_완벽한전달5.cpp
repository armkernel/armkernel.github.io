// 9_�Ϻ�������3
#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}


template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

// main      -      chronometry								hoo(int&&)
// 10(rvalue)���� => int&& arg(lvalue)  => �ٽ�rvalue�κ����� ���� =>

//   �� �������� value �Ӽ�����     

template<typename F> void chronometry(F f, int&& arg)
{
	// int&& arg = 10;   
	// 10 : rvalue,   arg : lvalue

	//f(arg); // hoo(int&) �� ã�� �ȴ�.
	f(static_cast<int&&>(arg)); // �ٽ� ���� �Ӽ��� rvalue�� �����ؼ�
							// ����
}



int main()
{
	hoo(10); // ok

	chronometry(hoo, 10); // �Ǿ� �մϴ�.
}




