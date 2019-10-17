#include <iostream>
using namespace std;

// T�� ������ ������ �����ϴ� ���
// 1. ����ü ���ø��� �����.
// 2. enum ��� value�� �ְ� false �� �ʱ�ȭ
// 3. �ش� ������ �����ϴ� �κ�Ư��ȭ ������ ����� value = true�� ����

template<typename T> struct xis_pointer
{
	//enum { value = false }; // C++11 ���� ��Ÿ��
	static constexpr bool value = false; // C++11 ��Ÿ��
};

template<typename T> struct xis_pointer<T*>
{
	// enum { value = true };
	static constexpr bool value = true;
};

template<typename T> void foo(T a)
{
	if (xis_pointer<T>::value)
		cout << "������ �Դϴ�." << endl;
	else
		cout << "������ �ƴ�" << endl;
}

int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}
