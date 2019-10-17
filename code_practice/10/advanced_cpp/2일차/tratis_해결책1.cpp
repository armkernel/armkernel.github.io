// tratis_해결책1.cpp
#include <iostream>
#include <type_traits>
using namespace std;


template<typename T> void printv(T v)
{
	//if ( is_pointer<T>::value )  // if ( false )

	// C++17 에서 나오는 정적 if 문.. 
	// 템플릿에서 조건을 만족하지 않으면 코드 생성을 하지 않는다.
	if constexpr (is_pointer<T>::value)
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}

// /std:c++latest  또는 /std:c++17

/*
void printv(int v)
{
//	if constexpr (is_pointer<T>::value)
//	else
		cout << v << endl;
}
*/
int main()
{
	int n = 0;
	printv(n); // 이 경우 문제..!!
	//printv(&n);
}
