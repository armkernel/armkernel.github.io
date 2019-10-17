// 9_bind1
#include <iostream>
#include <functional> // bind
using namespace std;
using namespace std::placeholders; // _1, _2, _3... 을 사용하기 위해

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}
int main()
{
	foo(1, 2, 3, 4); // 4항 함수

	// bind : M 항 함수를 N 항 함수로 변경, 단 N < M;
	bind(foo, 1, 2, 3, 4) (); // 4항함수 => 무항함수

	bind(foo, 1, _1, _2, _3) (7,8,9); // foo(1, 7, 8, 9)					
								// 4항 함수를 인자 1개 고정한 3항함수로


	bind(foo, 9, _2, _1, 7 ) (6, 4); // 9, 4, 6, 7 나오게 ? 채워 보세요
}







