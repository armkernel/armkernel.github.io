#include <iostream>
using namespace std;

struct A { int a; };
struct B { int b; };
struct C : public A, public B { int c; };

int main()
{
	C ccc;  // �޸� ��� �����غ�����..
	A* pA = &ccc; // 1000
//	B* pB = &ccc; // 1004
//	B* pB = (B*)&ccc; // 1004
	
	B* pB = static_cast<B*>(&ccc); // 1004
					// &ccc �ּҿ��� B�� ��ġ�� ã�Ƽ� �ּ� ��ȯ
					// �ش� �ּҿ� B�� ������ �������� �����Ƿ�
					// ����..
					// ������ �ð��� ����
					// &ccc + sizeof(A) 

	B* pB = reinterpret_cast<B*>(&ccc); // 1000
					// &ccc �ּҸ� ������ B ó�� ����
					// ������ �ʿ� ����. ������ �ð�..

	pB->b = 100; // ccc.a �� �ֱ�.



	cout << &ccc << endl; // 1000 �̶�� �����Ҷ�
	cout << pA   << endl; // ������ ������
	cout << pB   << endl; // ������ ������

}




