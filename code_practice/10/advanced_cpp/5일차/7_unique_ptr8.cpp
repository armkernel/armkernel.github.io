// 7_unique_ptr8
#include <iostream>
#include <memory>
using namespace std;

int main()
{
	unique_ptr<int> up1(new int);
	unique_ptr<int[]> up2(new int[10]); // C++14

	// ������ ��� ��� ������
	*up1 = 10;    // ok
//	up1[0] = 10;  // error

//	*up2 = 10;    // error
	up2[0] = 10;  //ok

	// ������ ������ ��� ��� ������.
	shared_ptr<int> sp(new int);
	unique_ptr<int> up(new int);

	shared_ptr<int> p1 = up;		// error
	shared_ptr<int> p2 = move(up);	// ok
	unique_ptr<int> p3 = sp;		// error
	unique_ptr<int> p4 = move(sp);  // error
}

// * ��� ����Ʈ �����͸� ����ϰ� �ͽ��ϴ�
// �Ʒ� �Լ��� ��ȯŸ���� ���� �ұ�� ? shared ? unique ?
//shared_ptr<int> AllocBuffer(int size)
unique_ptr<int> AllocBuffer(int size)
{
	return unique_ptr<int>(new int);
}
shared_ptr<int> ret1 = AllocBuffer(100);	
unique_ptr<int> ret2 = AllocBuffer(100);


int[3] a; // a�� Ÿ���� int[3];
int[4] a; // a�� Ÿ���� int[4];

//int[] : unknown size array type.. �̶�� �̸��� ���� Ÿ��!!
			// incomplete type �̹Ƿ� �� Ÿ���� ��ü�� ����� �����ϴ�.

//void foo(int[] arg) // ���� unknown size arraY �ƴմϴ�.
					// int* �Դϴ�.
// C++ ǥ�� ����Ʈ ������ : shared_ptr, weak_ptr, unique_ptr

int main()
{
	int n = 0;
	int* p = &n; // p�� ����Ʈ �����ͷ� �����Ҽ� ������� ?
	shared_ptr<int> p (&n);

//	observer_ptr<int> p(&n); // C++20
}
// cafe.naver.com/cppmaster �� cppmaster.h �޾� ��������..



 


