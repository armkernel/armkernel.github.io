// 9_완벽한전달3
#include <iostream>
using namespace std;

void foo(int a)  {}
void goo(int& a) { a = 100; }

// 완벽한 전달(perfect forwarding)
// 도착한 인자를 다른 함수에게 완벽하게 전달해 주는것

// 특정 함수의 성능을 측정하는 함수
template<typename F, typename T> 
void chronometry(F f, const T& arg)
{
	// 시간 기록
	f(arg);
	// 걸린 시간 출력
}
int main()
{
	int n = 10;
	//	foo(10);
	chronometry(foo, 10);
	chronometry(goo, n);

	cout << n << endl;
}




