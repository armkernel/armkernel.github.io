#include <iostream>
using namespace std;
// T�� ������ ������ �����ϴ� ���
// 1. ����ü ���ø��� �����.
// 2. static constexpr bool value�� �ְ� false �� �ʱ�ȭ
// 3. �ش� ������ �����ϴ� �κ�Ư��ȭ ������ ����� value = true�� ����

template<typename T> struct xis_reference
{
	static constexpr bool value = false;
};
template<typename T> struct xis_reference<T&>
{
	static constexpr bool value = true;
};
template<typename T> struct xis_reference<T&&>
{
	static constexpr bool value = true;
};

// ::value �� ���� ���� �ʴ�.
// C++14 �� variable template ���� ���
template<typename T> 
bool xis_reference_v = xis_reference<T>::value;

int main()
{
	// xis_referenence ����� ������. xis_pointer�� ���� �߻����غ�����
	cout << xis_reference<int>::value << endl; // false
	cout << xis_reference<int&>::value << endl; // true
	cout << xis_reference_v<int&> << endl; // true
}

//--------------------------------------
/*
template<typename T> class list {};       // Ŭ���� ���ø�
template<typename T> void foo(T a) {};    // �Լ� ���ø�
template<typename T> using List = list<T>;// using ���ø�
List<int> s; // == list<int>

template<typename T> bool v = xis_pointer<T>::value;  // variable template
v<int> // =xis_pointer<int>::value
v<int*>
v<int>
*/
