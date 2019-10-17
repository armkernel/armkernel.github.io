#include <iostream>
using namespace std;

// __FUNCTION__ : �Լ��̸�. C++ ǥ��
// __FUNCSIG__  : �Լ��̸� + signature, VC++ ������ ����
//                 g++ : __PRETTY_FUNCTION__ ���

void foo(int& a)       { cout << __FUNCSIG__ << endl; }
void foo(const int& a) { cout << __FUNCSIG__ << endl; }
void foo(int&& a)      { cout << __FUNCSIG__ << endl; }

int main()
{
	int n = 10;
	foo(n);		// 1�� ȣ��, ������ 2��
	foo(10);	// 3�� ȣ��, ������ 2��

	int& r1 = n;
	foo(r1);	// 1�� ȣ��, ������ 2��

	int&& r2 = 10;	// 10�� rvalue ������ r2�� lvalue �Դϴ�. "�߿�!!"
	foo(r2);	// 1�� ȣ��, ������ 2��
	foo(r2+1);  // 3�� ȣ��, ������ 2��

	// r2�� 3���� ȣ��ǰ� �Ϸ��� lvalue => rvalue�� �Ӽ� ���� �ʿ�
	foo(static_cast<int&&>(r2)); // 3��

//	foo(static_cast<int&>(10)); // 1���� �ɱ�..?? error

	
	// int&, int&& : ����Ÿ Ÿ��
	// rvalue, lvalue : ǥ���Ŀ� ���� �Ӽ�.!!
}


