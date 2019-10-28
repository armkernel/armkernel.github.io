#include <iostream>
#include <type_traits>
using namespace std;

// enable_if �� ����� �Լ� ���ø�
// ������ �����ϸ� �Լ� ���ø� ���
// ������ �������� ���ϸ� SFINAE �� Ư¡�� ���� �ĺ����� ����
// �ٸ� ������ ���� �̸� �Լ� ��� ����!

template<typename T>
typename enable_if< is_integral<T>::value, T>::type
gcd(T a, T b)
{
	cout << "T" << endl;
	return a;
}


double gcd(double a, double b)
{
	cout << "double" << endl;
	return 0;
}


int main()
{
	gcd(3, 6);			
	gcd(3.4, 2.8);		
	gcd(3.4f, 2.8f);	
}



