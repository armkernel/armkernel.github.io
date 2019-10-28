// 6_int2type7
#include <iostream>
using namespace std;

// int2type : int 형 상수를 독립된 타입으로 만드는 도구
/*
template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};
// true, false           : 참 거짓을 나타내는 값, 같은 타입
// true_type, false_type : 참 거짓을 나타내는 타입, 다른 타입
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

// is_pointer 등의 traits는 아래처럼 만듭니다.
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};

int main()
{
	integral_constant<int, 0>   t0;
	integral_constant<int, 1>   t1;
	integral_constant<short, 0> t2;
}

*/
#include <type_traits> // 이 안에 위에 코드가 있습니다.

template<typename T> void printv_imp(T v, true_type )
{
	cout << v << " : " << *v << endl;
}
template<typename T> void printv_imp(T v, false_type )
{
	cout << v << endl;
}
template<typename T> void printv(T v)
{
	printv_imp(v, is_pointer<T>() );
}
int main()
{
	int n = 0;
	printv(n);
}


