// 9_�򰡵�������ǥ����.  - 143 page
#include <iostream>
using namespace std;

/*
int foo(int a) 
{
	cout << "foo" << endl;
	return 0;
}
*/

// �򰡵��� ���� ǥ���Ŀ��� ����� �Լ��� ���� ������ �ȴ�.
int foo(int a);

int main()
{
	int n = 0;
	cout << sizeof( n )	<< endl;     // 4
	cout << sizeof( &foo ) << endl;  // �ּ��� ũ��. 32bitȯ�� 4
	//cout << sizeof( foo )  << endl;  // error. �Լ��� ũ��� ���Ҽ� ����
	cout << sizeof( foo(0) ) << endl;  // �Լ� ��ȯ���� ũ��. 4

	// unevaluated expression(�򰡵��� ���� ǥ����)
	// �Լ� ȣ����� ������ �Լ��� ȣ������ �ʴ� ��. 4���� �ִ�.
	
	sizeof(foo(0));		// ��ȯ�� ũ�� 4
	
	decltype( foo(0) ) n2; // ��ȯ���� ���� Ÿ��

	const type_info& r = typeid(foo(0));
	
	bool b = noexcept( foo(0) );
}


