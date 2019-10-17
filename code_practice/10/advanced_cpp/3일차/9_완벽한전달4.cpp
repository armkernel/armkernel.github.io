// 9_�Ϻ�������3
#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 100; }

// �Ϻ��� �����Ϸ���
// 1. ���ڴ� ���纻�� �����Ǹ� �ȵȴ�. - ����
// 2. const�� �ٿ��� �ȵȴ�.
// 3. int& �� int&& ������ �Լ��� 2�� �����Ѵ�.
//   (const int&, const volatile int & � �ʿ� �ϴ�.)
template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}
int main()
{
	int n = 10;

	chronometry(foo, 10);
	chronometry(goo, n);

	cout << n << endl;
}




