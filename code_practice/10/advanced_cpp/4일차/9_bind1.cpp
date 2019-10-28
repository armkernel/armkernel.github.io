// 9_bind1
#include <iostream>
#include <functional> // bind
using namespace std;
using namespace std::placeholders; // _1, _2, _3... �� ����ϱ� ����

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}
int main()
{
	foo(1, 2, 3, 4); // 4�� �Լ�

	// bind : M �� �Լ��� N �� �Լ��� ����, �� N < M;
	bind(foo, 1, 2, 3, 4) (); // 4���Լ� => �����Լ�

	bind(foo, 1, _1, _2, _3) (7,8,9); // foo(1, 7, 8, 9)					
								// 4�� �Լ��� ���� 1�� ������ 3���Լ���


	bind(foo, 9, _2, _1, 7 ) (6, 4); // 9, 4, 6, 7 ������ ? ä�� ������
}







