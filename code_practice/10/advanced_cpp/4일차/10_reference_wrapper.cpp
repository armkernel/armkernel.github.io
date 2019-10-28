// 10_reference_wrapper1.cpp
#include <iostream>
#include <functional>
using namespace std;

// C++ ���� : �ѹ� ����Ų �޸𸮴� �����Ҽ� ����. ������ ���
//			 ���� ����� ���� �̵��Ѵ�.
// reference_wrapper : �̵� ������ ����.. ���Կ���� ������ �̵�

// �ᱹ "1. �ּҸ� ����"   "2. ��¥ ����Ÿ������ ��ȯ����"
template<typename T> struct xreference_wrapper
{
	T* obj;
public:
	xreference_wrapper(T& r) : obj(&r) {}

	// ��¥ ������ ȣȯ�Ǿ�� �Ѵ�.
	operator T&() { return *obj; }
};

int main()
{
	int n1 = 10;
	int n2 = 20;

//	int& r1 = n1;
//	int& r2 = n2;

	xreference_wrapper<int> r1 = n1;
	xreference_wrapper<int> r2 = n2;

	r1 = r2;

	int& r3 = r1;

	// ��� ������ ������
	cout << n1 << endl;
	cout << n2 << endl;
	cout << r1 << endl;
	cout << r2 << endl;
}