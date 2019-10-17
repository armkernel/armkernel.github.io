#include <iostream>
#include <type_traits>
using namespace std;

/*
template<typename T> void printv(T v)
{
	if ( is_pointer<T>::value )  // is_pointer_v<T>
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}
*/
// printv(n) 으로 사용하면 아래 코드가 생성됩니다.
void printv(int v)
{
	if ( false ) 
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}
// printv(&n) 으로 사용하면 아래 코드가 생성됩니다.
void printv(int* v)
{
	if (true)
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}
int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}
