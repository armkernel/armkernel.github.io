// 1_ĳ����7.cpp
#include <iostream>
using namespace std;

class Animal
{
public:
	// �����Լ��� ������
	// �����Լ� ���̺��� ����� ����, �׾ȿ� Ÿ�� ������ ����
	// ���̰�,
	// �� ��ü�� ���̺��� ����Ű�� �˴ϴ�.

	// ��� :�����Լ��� ���� ��ü�� dynamic_cast�� ����Ҽ�
	//			�����ϴ�.
	virtual ~Animal() {}
};

class Dog : public Animal
{
public:
	void Cry() {}
};
//---------------------
void foo(Animal* p)
{
	// Ȥ�� p�� Dog ��� �Ʒ� ó�� �ϰ� �ʹ�.
	//p->Cry(); // error

	// Down Casting : ��� Ÿ���� => �Ļ� Ÿ������ ����
	//Dog* pDog = static_cast<Dog*>(p); // ������ : ok.
									  // �׻� ĳ���� ����

	// p �� ���� Dog �϶��� �����ؾ� �Ѵ�.
	// ������ �ð��� �ƴ� ����ð��� �������� ĳ����
	Dog* pDog = dynamic_cast<Dog*>(p);

	cout << pDog << endl;
}
int main()
{
	Animal a; foo(&a);
	Dog    d; foo(&d);
}

// C++ ĳ����

// static_cast   - ������ 
 
// reinterpret_cast - ������

// const_cast	- ������ 

// dynamic_cast - ����ð�(������� ����)





