// 5_move����1
#include <iostream>
#include <string>
using namespace std;

// rule of 3
// �����Ͱ� �ְ� �����ڿ��� �ڿ� �Ҵ��ϸ�
// "�Ҹ���, ���� ������, ���Կ�����"�� �ʿ��ϴ�.

// �� �ҽ��� �ٽ� - ���������, ���Կ����� ����� ���.

class People 
{
	string name;
	int    age;
	char*  addr;
public:
	People(string n, int a, const char* ad) : name(n), age(a)
	{
		addr = new char[strlen(ad) + 1];
		strcpy(addr, ad);
	}
	~People() { delete[] addr; }

	// ���� ������
	People(const People& p) : name(p.name), age(p.age)
	{
		// �����Ͱ� �ƴ� ����� �׳� �����ص� ������
		// �����ʹ� �޸𸮸� ����(�Ǵ� �������)
		addr = new char[strlen(p.addr) + 1];
		strcpy(addr, p.addr);
	}

	// ���� �����ڸ� ���� ���� ��κ� ���Կ����ڵ� �ʿ� �ϴ�.
	// ��Ģ 1.  ��ȯ���� �ڽ��� ������ �ؾ� �Ѵ�.
	//     2.   �ڽŰ��� ������ �����ؾ� �Ѵ�.
	//    3.  ��� Ŭ������ �ִٸ� ��� Ŭ������ ���Կ����ڵ� ȣ���Ѵ�.
	//    4.  ���ܿ� �����ϰ� �ۼ��ؾ� �Ѵ�. - ���� - copy and swap �׸�
	People& operator=(const People& p)
	{
		// �ڽŰ��� ���� ����
		if (&p == this) return *this;

		// ��� Ŭ������ �ִٸ� ��� Ŭ������ ���Կ����ڵ� ȣ���ؾ� �Ѵ�.
		//Base::operator=(p);


		// �����Ͱ� �ƴϸ� �׳� ����
		name = p.name;
		age = p.age;

		// �����ʹ� ���� �޸𸮸� �����ϰ�, ���ο� �޸𸮿� ����
		delete[] addr;
		addr = new char[strlen(p.addr) + 1];
		strcpy(addr, p.addr);
		return *this;
	}
};
int main()
{
	People p1("kim", 10, "seoul");
	p1 = p1;

	People p2 = p1; // ���� ������
	p2 = p1;		// p2.operator=(p1).  ���Կ�����


	int n = 10;

	n = n;

	(n = 20) = 30; // ???
}
