// 6_int2type3
#include <iostream>
#include <type_traits>
using namespace std;


template<typename T> void printv_imp(T v, YES)
{
	cout << v << " : " << *v << endl;
}
template<typename T> void printv_imp(T v, NO)
{
	cout << v << endl;
}

template<typename T> void printv(T v)
{
	// 함수 오버로딩에 의한 분기 : 컴파일 시간에 이루어진다.
	//		선택되지 않은 함수(템플릿)은 실제 C++코드로 생성되지 않는다
	printv_imp(v, ? );



	/*
	// if 문에 의한 분기 : 실행시간 분기.. 
	if (is_pointer<T>::value)    // if ( false )
		printv_pointer(v);
	else
		printv_not_pointer(v);
	*/

}

int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}

