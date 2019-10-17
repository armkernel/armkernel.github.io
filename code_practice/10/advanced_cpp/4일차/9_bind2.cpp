// 9_bind1
#include <iostream>
#include <functional> // bind
using namespace std;
using namespace std::placeholders; // _1, _2, _3... �� ����ϱ� ����

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}
void goo(int) { cout << "goo" << endl; }

int main()
{
	// �Ϲ� �Լ� ������ ����
	// 1. �Լ��� ��´�. �Լ���ü�� ������ ����.
	// 2. ���ڰ� ������ �ٸ� �Լ��� ������ ����.
	//void(*f)(int); 

	// C++ : �Լ� ������ ��� function �� ������� - C++11
	function<void(int)> f;
	f = &goo;
	
	f(10); // goo(10)

	f = bind(&foo, 1, 2, 3, _1);
	f(10); // foo(1,2,3,10)

	f = [](int a) { cout << "lambda" << endl; };
	f(10);

	// C++ GUI ���̺귯�� : nana (C++11/14�� Ȱ���� ���̺귯��)
}













