#include <iostream>
#include <type_traits>
using namespace std;

#define CHECK_VALUE_CATEGORY(...)									\
	if (is_lvalue_reference< decltype(( __VA_ARGS__ )) >::value)	\
		cout << "lvalue" << endl;									\
	else                                                            \
		cout << "rvalue" << endl;

int main()
{
	// value category 를 조사하는 방법
	int n = 0;

	CHECK_VALUE_CATEGORY(10);
	CHECK_VALUE_CATEGORY(n);
	CHECK_VALUE_CATEGORY(n + n);
	CHECK_VALUE_CATEGORY("hello");

//	if (is_lvalue_reference< decltype( ( n+1 ) ) >::value)
//		cout << "lvalue" << endl;
//	else
//		cout << "rvalue" << endl;
}


