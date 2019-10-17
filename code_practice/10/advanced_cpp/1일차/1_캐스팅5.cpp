#include <iostream>
using namespace std;

// const_cast : ���� Ÿ�� ��ü�� const, volatile �Ӽ�
//				����.

int main()
{
	const int c = 10;

	int* p1 = &c; // error
	int* p1 = (int*)&c; // ok
	int* p1 = static_cast<int*>(&c); // error
	int* p1 = reinterpret_cast<int*>(&c); // error
	int* p1 = const_cast<int*>(&c); // ok.

	volatile int n = 10;
	int* p2 = &n; // error
	volatile int* p2 = &n; // ok..

	int* p2 = const_cast<int*>(&n); //ok

}

// �Ʒ� �ڵ� �ذ��� ������
int main()
{
	const int c = 10;

	// c�� �ּҸ� p�� ��� ������..
	// ��, C++ ĳ���� ���
	//char* p = &c ; // error
	char* p = reinterpret_cast<char*>(&c); // error
								// const ���� �ȵ�.
	char* p = const_cast<char*>(&c);// error. �ٸ� Ÿ��

	char* p = reinterpret_cast<char*>(
					const_cast<int*>(&c));//ok

	char* p = (char*)&c ; // ok.

}




