// 9_�Ϻ�������3
#include <iostream>
using namespace std;

void foo(int a)  {}
void goo(int& a) { a = 100; }

// �Ϻ��� ����(perfect forwarding)
// ������ ���ڸ� �ٸ� �Լ����� �Ϻ��ϰ� ������ �ִ°�

// Ư�� �Լ��� ������ �����ϴ� �Լ�
template<typename F, typename T> 
void chronometry(F f, const T& arg)
{
	// �ð� ���
	f(arg);
	// �ɸ� �ð� ���
}
int main()
{
	int n = 10;
	//	foo(10);
	chronometry(foo, 10);
	chronometry(goo, n);

	cout << n << endl;
}




