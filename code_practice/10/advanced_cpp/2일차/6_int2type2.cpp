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
// printv(n) ���� ����ϸ� �Ʒ� �ڵ尡 �����˴ϴ�.
void printv(int v)
{
	if ( false ) 
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}
// printv(&n) ���� ����ϸ� �Ʒ� �ڵ尡 �����˴ϴ�.
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
