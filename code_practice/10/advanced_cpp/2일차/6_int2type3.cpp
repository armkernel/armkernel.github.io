// 6_int2type3
#include <iostream>
#include <type_traits>
using namespace std;

// 포인터인 경우와 포인터가 아닌 경우를 하나의 함수로 만들지 말자.!!
// 서로 다른 함수로 구현한다.

template<typename T> void printv_pointer(T v)
{
	cout << v << " : " << *v << endl;
}
template<typename T> void printv_not_pointer(T v)
{
	cout << v << endl;
}
template<typename T> void printv(T v)
{
	if (is_pointer<T>::value)    // if ( false )
		printv_pointer(v);
	else
		printv_not_pointer(v);

		
}

int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}

