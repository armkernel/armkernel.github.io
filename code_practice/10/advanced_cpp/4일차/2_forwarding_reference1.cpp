// 2_forwarding_reference1
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 10;

	// 1. ���纻 ����!
	auto a1 = n; // ok
	auto a2 = 10;// ok

	auto& a3 = n; // ok
	auto& a4 = 10;// error

	// auto �� ���ø��� �����ϴ�.
	// foo(T&& arg);   foo(10)  => 10�� ���� T ����
	// auto&& arg = 10;         => 10�� ���� auto ����

	auto&& a3 = n; // ok.
	auto&& a4 = 10;// ok.

	vector<bool> v(10, 0);
	auto   a6 = v[0]; // ok
	auto&  a7 = v[0]; // error
	auto&& a8 = v[0]; // ok


	for (auto& n : v) // error
	{

	}
}


