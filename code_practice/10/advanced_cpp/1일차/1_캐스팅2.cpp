// 1_ĳ����2.cpp
#include <iostream>
using namespace std;
// C++ �� 4���� ĳ����
// static_cast  : �⺻ ĳ����
//				1. ǥ�� Ÿ���� ������ ĳ����
//				2. void* => �ٸ� Ÿ��*
//              3. ���ü��� ���� Ÿ���� �ּҴ� ĳ���� �ȵ�.
//					(�ϰ� �ʹٸ�, reinterpret_cast)
//				4. rvalue => lvalue�� ����
// reinterpret_cast
// const_cast
// dynamic_cast
int main()
{
	double d = 3.4;
	//int    n = d; // ok
	int    n = static_cast<int>(d); // ok

	//int* p1 = malloc(100); // void* => int* ��ȯ
							// C : ok, C++ : error

	int* p1 = static_cast<int*>(malloc(100)); // ok

	int* p2 = static_cast<int*>(&d); // double* => int*
									// error
	int&& r1 = n; // error
	int&& r1 = static_cast<int&&>(n); // ok..
					// �� �ڵ�� rvalue�� lvalue�� ����
					// ��, �Ӽ��� �����ϴ� ĳ����
	int&  r2 = static_cast<int&>(10);// error

}