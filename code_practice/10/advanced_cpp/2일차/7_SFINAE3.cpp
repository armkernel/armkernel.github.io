// 7_SFINAE3
#include <iostream>
using namespace std;

void foo(...) { cout << "..." << endl; }

/*
template<typename T> void foo(T a) 
{
	typename T::type n;    // 1. SFINAE ��Ģ ����	2. Error
						// ���� Error
}
*/

// SFINAE �� �Ʒ� 3���� ��츸 ��밡��

// 1. �Լ� ��ȯ Ÿ�� - ���� �θ� ���
template<typename T> typename T::type foo(T a) { return 0; }

// 2. �Լ� ���� - �����ڵ�.. ��ȯŸ���� ���� ��쿡 �ַ� ���
template<typename T> void foo(T a, typename T::type b = 0) { }


// 3. ���ø� ���� - �Լ� ��ü�� ����� �������� ���� ������ �ִ�.
template<typename T, typename T2 = typename T::type> void foo(T a) { }


int main()
{
	foo(10);
}





