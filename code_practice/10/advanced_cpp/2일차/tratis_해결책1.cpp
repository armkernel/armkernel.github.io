// tratis_�ذ�å1.cpp
#include <iostream>
#include <type_traits>
using namespace std;


template<typename T> void printv(T v)
{
	//if ( is_pointer<T>::value )  // if ( false )

	// C++17 ���� ������ ���� if ��.. 
	// ���ø����� ������ �������� ������ �ڵ� ������ ���� �ʴ´�.
	if constexpr (is_pointer<T>::value)
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}

// /std:c++latest  �Ǵ� /std:c++17

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
	printv(n); // �� ��� ����..!!
	//printv(&n);
}
