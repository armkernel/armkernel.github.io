// 9_bind1
#include <iostream>
#include <functional> // bind
using namespace std;
using namespace std::placeholders; // _1, _2, _3... 을 사용하기 위해

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}
void goo(int) { cout << "goo" << endl; }

int main()
{
	// 일반 함수 포인터 단점
	// 1. 함수만 담는다. 함수객체를 담을수 없다.
	// 2. 인자가 갯수가 다른 함수를 담을수 없다.
	//void(*f)(int); 

	// C++ : 함수 포인터 대신 function 을 사용하자 - C++11
	function<void(int)> f;
	f = &goo;
	
	f(10); // goo(10)

	f = bind(&foo, 1, 2, 3, _1);
	f(10); // foo(1,2,3,10)

	f = [](int a) { cout << "lambda" << endl; };
	f(10);

	// C++ GUI 라이브러리 : nana (C++11/14를 활용한 라이브러리)
}













