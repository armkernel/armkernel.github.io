#include <iostream>
using namespace std;

// 아래 헤더에 이미 많은 traits 가 있습니다
#include <type_traits>

template<typename T> void foo()
{
	bool b1 = std::is_array<T>::value;// C++11 부터.
	bool b1 = std::is_array_v<T>;     // C++14 부터

	//std::is_
}
int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}


