// 7_람다표현식5
#include <iostream>
#include <type_traits>
using namespace std;

int main()
{
	auto f = [](int& a)  { return a; };

	int n = 0;

	if (is_lvalue_reference_v<decltype(f(n))>)
		cout << "참조반환" << endl;
	else
		cout << "값반환" << endl;
}



