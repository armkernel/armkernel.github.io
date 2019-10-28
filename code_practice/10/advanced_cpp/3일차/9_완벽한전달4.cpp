// 9_완벽한전달3
#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 100; }

// 완벽히 전달하려면
// 1. 인자는 복사본이 생성되면 안된다. - 참조
// 2. const를 붙여도 안된다.
// 3. int& 와 int&& 버전의 함수를 2개 제공한다.
//   (const int&, const volatile int & 등도 필요 하다.)
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




