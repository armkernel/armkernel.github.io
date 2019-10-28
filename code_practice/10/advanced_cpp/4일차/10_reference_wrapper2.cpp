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
//--------------------------
void foo(int& a) { a = 100; }

// bind �� ������ �����ߴٰ� �ٽ� ȣ���Ҷ� ����մϴ�.
template<typename T> void Bind(T arg)
{
	foo(arg);
}

// xreference_wrapper�� ����� �Լ�
template<typename T> 
xreference_wrapper<T> xref(T& obj)
{
	return xreference_wrapper<T>(obj);
}

int main()
{
	int n = 0;
	//Bind(&n); // T�� int* �ε� int& �� ��ȯ�ɼ� ����. error

//	xreference_wrapper<int> r(n);
//	Bind(r); // �ᱹ �ּҸ� �����°�. �׷���, r�� int& �� ��ȯ����

//	Bind(xreference_wrapper<int>(n));

	Bind( xref(n) );

	cout << n << endl; // 100 

	double d;
	int n = d;

	Point pt;
	int n = pt; // pt.operator int()
	int& r = pt; // pt.operator int&()
}

