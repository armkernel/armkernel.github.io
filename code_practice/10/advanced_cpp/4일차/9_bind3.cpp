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

		f = bind(&foo, _1, n); // n의 값을 복사해서 보관한다.
							// 왜 참조 보관하지 않을까 ?
							// 블럭을 벗어나면 파괴 될수 있다
	}
	*/

	int n = 0;

	f = bind(&foo, _1, ref(n) ); // n을 참조로 보관

	f(10); // foo(10, n)

	cout << n << endl; // 얼마 나올까요 ?
}













