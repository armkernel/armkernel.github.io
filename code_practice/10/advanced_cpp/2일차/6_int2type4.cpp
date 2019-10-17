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
	// �Լ� �����ε��� ���� �б� : ������ �ð��� �̷������.
	//		���õ��� ���� �Լ�(���ø�)�� ���� C++�ڵ�� �������� �ʴ´�
	printv_imp(v, ? );



	/*
	// if ���� ���� �б� : ����ð� �б�.. 
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

