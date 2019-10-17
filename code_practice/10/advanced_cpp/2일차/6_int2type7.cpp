// 6_int2type7
#include <iostream>
using namespace std;

// int2type : int �� ����� ������ Ÿ������ ����� ����
/*
template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};
// true, false           : �� ������ ��Ÿ���� ��, ���� Ÿ��
// true_type, false_type : �� ������ ��Ÿ���� Ÿ��, �ٸ� Ÿ��
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

// is_pointer ���� traits�� �Ʒ�ó�� ����ϴ�.
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};

int main()
{
	integral_constant<int, 0>   t0;
	integral_constant<int, 1>   t1;
	integral_constant<short, 0> t2;
}

*/
#include <type_traits> // �� �ȿ� ���� �ڵ尡 �ֽ��ϴ�.

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


