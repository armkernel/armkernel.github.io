#include <iostream>
using namespace std;

// reinterpret_cast
// 1. ���� �ٸ� Ÿ���� �ּҸ� ĳ����
// 2. ���� <=> ������   ĳ����
// 3. ���� �ٸ� Ÿ���� ���� �������� ĳ����


int main()
{
	double d = 3.4;

	int* p1 = (int*)&d; // ok. ������ �Ǽ� ���� �ǵ����� �˼� ����
	int* p2 = static_cast<int*>(&d); // error
	int* p3 = reinterpret_cast<int*>(&d); // ok

	// ���� => �����ͷ� ��ȯ
	int* p4 = 10; //error
	int* p4 = (int*)10; //ok
	int* p4 = static_cast<int*>(10); // error
	int* p4 = reinterpret_cast<int*>(10); // ok

}




