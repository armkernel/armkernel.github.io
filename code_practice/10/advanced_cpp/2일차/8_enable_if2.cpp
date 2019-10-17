#include <iostream>
#include <type_traits>
using namespace std;

// �ִ� ������� ���ϴ� �Լ�
// ��, ���� �迭Ÿ�Ը� ��밡���ϰ� �ϰ� �ʹ�.

// ��� 1. C++11 static_assert() ���
// Ư¡ : ������ �������� ������ ������ error
template<typename T> 
T gcd(T a, T b)
{
	static_assert( is_integral<T>::value, "T is no integral");
	return a;
}
// �Ǽ� �迭�� �Ʒ� �Լ��� ȣ��ǰ� �ϰ� �ʹ�.
double gcd(double a, double b) 
{ 
	cout << "double" << endl; 
	return 0; 
}
int main()
{
	gcd(3, 6);			// T���
	gcd(3.4, 2.8);		// double ���
	gcd(3.4f, 2.8f);	// T ��� - static_assert ������ ����
}



