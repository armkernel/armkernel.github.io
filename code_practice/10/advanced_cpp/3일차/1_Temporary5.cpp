#include <iostream>
using namespace std;

class Test
{
public:
	//void foo() { cout << "&" << endl; } // ��� ��ü�� ȣ�Ⱑ��

	void foo() & { cout << "&" << endl; } // �̸� �ִ� ��ü�� 
										// ��밡��
	void foo() && { cout << "&&" << endl; } // temporary ��
									// ��밡��
};
int main()
{
	Test t;
	t.foo();
	Test().foo();

	((Test*)0)->foo(); // &
}

