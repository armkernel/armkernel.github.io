#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void foo(T a)
{
	// T�� ������ ���ο� ���� �ٸ��� �ϱ�
	// if ��
	if (is_pointer<T>::value)
	{
		// ...
		// ��, "*a = 10" ���� �ڵ�� ����Ҽ� ����.
	}
	else
	{
		// ...
	}
	// "*a = 10" �� ����ϰ� �ʹٸ�

	// 1. if constexpr ��� - �ذ�å 1. ����
	if constexpr (is_pointer<T>::value)
	{
		*a = 10; // ok!!!
	}
	else 
	{
	}
	// 2. true_type, false_type ���� �����ε�

	foo_imp(a, is_pointer<T>());
}
template<typename T> void foo_imp(T a, true_type) {}  // *a = 10����
template<typename T> void foo_imp(T a, false_type) {}

// 3. �Լ� ���ø��� 2�� ����� enable_if �� ���ǿ� ���� ����ϵ���
template<typename T> 
typename enable_if<is_pointer<T>::value>::type
foo(T a)
{
}

template<typename T>
typename enable_if< !is_pointer<T>::value >::type
foo(T a)
{
}
// ����� ���� ����
// 2���� true_type/false_type   - 3���� �Լ�
// 3���� enable_if				- 2���� �Լ�
// 1���� if constexpr			- 1���� �Լ��ȿ���.

// github.com/aosp-mirrow
// platform_system_core (2page)
// libutils/include/utils/typehelpers.h �ȿ� copy_type






