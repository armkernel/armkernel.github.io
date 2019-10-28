// 6_�����Լ�1
#include <iostream>
using namespace std;

class Animal
{
public:
	void Cry() { cout << "1" << endl; }
};
class Dog : public Animal
{
public:
	// �Լ� �������̵�(override)
	void Cry() { cout << "2" << endl; }
};
int main()
{
	Animal a; a.Cry(); // 1
	Dog    d; d.Cry(); // 2

	Animal* p = &d;

	//if (������Է� == 1) p = &a;

	p->Cry();
}

// p->Cry() �� � �Լ��� �����ұ� ? => �Լ� ���ε�

// 1. static binding : ������ �ð��� �����Ϸ��� �Լ��� ����
//					  ������ ������ Ÿ������ ���� => Animal Cry()
// early binding. ������. ������̴�.
//						C++, C#

// 2. dynamic binding : ������ �ÿ� p�� ����Ű�� �޸� �����ϴ� ����
//					�ڵ� ����. ����� ������ ȣ��
//					Dog Cry()
// late binding. ������. �����̴�.
//						java, swift, kotlin, objective-C
//						C++, C#�� virtual �Լ�.