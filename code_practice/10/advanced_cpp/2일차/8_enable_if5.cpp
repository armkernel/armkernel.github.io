#include <iostream>
using namespace std;

#include <type_traits>

/*
template<typename T> void printv_imp(T v, true_type)
{
	cout << v << " : " << *v << endl;
}
template<typename T> void printv_imp(T v, false_type)
{
	cout << v << endl;
}
template<typename T> void printv(T v)
{
	printv_imp(v, is_pointer<T>());
}
*/

template<typename T> 
typename enable_if< is_pointer<T>::value >::type 
printv(T v)
{
	cout << v << " : " << *v << endl;
}

template<typename T> 
typename enable_if< !is_pointer<T>::value >::type
printv(T v)
{
	cout << v << endl;
}


int main()
{
	int n = 0;
	printv(n);
}


