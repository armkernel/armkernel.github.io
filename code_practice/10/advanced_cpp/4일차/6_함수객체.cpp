// 6_�Լ���ü
#include <iostream>
using namespace std;
// �Լ� ��ü(function object) : �Լ� ó�� ()�� ����ؼ� ȣ�Ⱑ����
//								��ü
// ������ "Callable Object"��� �� ����մϴ�
struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	Plus p; // �Լ��� �ƴ϶� ��ü
	int n = p(1, 2); // �ٽ�!!
					// p.operator()(1,2) 

	// a + b; // a.operator+ (b)
	// a - b; // a.operator-(b)
	// a();   // a.operator()()
	// a(1,2);// a.operator()(1,2)
}



