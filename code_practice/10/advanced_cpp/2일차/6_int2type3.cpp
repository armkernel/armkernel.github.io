// 6_int2type3
#include <iostream>
#include <type_traits>
using namespace std;

// �������� ���� �����Ͱ� �ƴ� ��츦 �ϳ��� �Լ��� ������ ����.!!
// ���� �ٸ� �Լ��� �����Ѵ�.

template<typename T> void printv_pointer(T v)
{
	cout << v << " : " << *v << endl;
}
template<typename T> void printv_not_pointer(T v)
{
	cout << v << endl;
}
template<typename T> void printv(T v)
{
	if (is_pointer<T>::value)    // if ( false )
		printv_pointer(v);
	else
		printv_not_pointer(v);

		
}

int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}

