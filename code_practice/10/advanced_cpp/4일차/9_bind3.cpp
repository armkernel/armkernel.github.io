#include <iostream>
#include <functional> 
using namespace std;
using namespace std::placeholders; 

void foo(int a, int& b) { b = 100; }

int main()
{
	function<void(int)> f;

	/*
	{
		int n = 0;

		f = bind(&foo, _1, n); // n�� ���� �����ؼ� �����Ѵ�.
							// �� ���� �������� ������ ?
							// ���� ����� �ı� �ɼ� �ִ�
	}
	*/

	int n = 0;

	f = bind(&foo, _1, ref(n) ); // n�� ������ ����

	f(10); // foo(10, n)

	cout << n << endl; // �� ���ñ�� ?
}













