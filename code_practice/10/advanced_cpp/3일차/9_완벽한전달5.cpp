// 9_완벽한전달3
#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}


template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

// main      -      chronometry								hoo(int&&)
// 10(rvalue)전달 => int&& arg(lvalue)  => 다시rvalue로변경후 전달 =>

//   이 과정에서 value 속성변경     

template<typename F> void chronometry(F f, int&& arg)
{
	// int&& arg = 10;   
	// 10 : rvalue,   arg : lvalue

	//f(arg); // hoo(int&) 를 찾게 된다.
	f(static_cast<int&&>(arg)); // 다시 원래 속성인 rvalue로 변경해서
							// 전달
}



int main()
{
	hoo(10); // ok

	chronometry(hoo, 10); // 되야 합니다.
}




