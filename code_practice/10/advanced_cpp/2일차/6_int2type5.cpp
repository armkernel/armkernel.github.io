// 6_int2type3
#include <iostream>
#include <type_traits>
using namespace std;

template<int N> struct int2type
{
	enum { value = N };
};

template<typename T> void printv_imp(T v, int2type<1>)
{
	cout << v << " : " << *v << endl;
}
template<typename T> void printv_imp(T v, int2type<0>)
{
	cout << v << endl;
}


template<typename T> void printv(T v)
{
	// 115 page¿«µµ
	printv_imp(v, int2type< is_pointer<T>::value >()  );
				// int2type<0>
				// int()
}



int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}

