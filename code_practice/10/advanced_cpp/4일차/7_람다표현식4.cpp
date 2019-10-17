// 9_완벽한전달3
#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

void koo(int a, int b, int c) {}
int joo() { return 100; }

// C++11 가변 인자 템플릿
template<typename F, typename ... T>
decltype(auto) chronometry(F&& f, T&& ... arg)
{
	return invoke( std::forward<F>(f), 
				   std::forward<T>(arg)...);
}

int main()
{
	hoo(10);
	chronometry(hoo, 10);
	chronometry(koo, 1, 2, 3);
	int ret = chronometry(joo);
}


