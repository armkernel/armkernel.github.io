// 3_traits1.cpp    - 115 page�� ����� ����..
#include <iostream>
using namespace std;

// Traits(Ư��) : T(Ÿ��)�� �پ��� �Ӽ��� �����ϴ� ���
template<typename T> void printv(T v)
{
	if ( T �� ������ ��� )
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}
int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}
