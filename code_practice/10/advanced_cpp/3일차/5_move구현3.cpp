// 5_move����1
#include <iostream>
#include <string>
using namespace std;

// rule of 5
// �����Ͱ� �ְ� �����ڿ��� �ڿ� �Ҵ��ϸ�
// "�Ҹ���, ���� ������, ���Կ�����"�� �ʿ��ϴ�.
// C++11 �߰� : "move ������", "move ���Կ�����"


// �� �ҽ��� �ٽ� - move ������, move���Կ����� ����� ���.

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

	People(const People& p) : name(p.name), age(p.age)
	{
		cout << "copy constructor" << endl;
		addr = new char[strlen(p.addr) + 1];
		strcpy(addr, p.addr);
	}
	People& operator=(const People& p)
	{
		cout << "copy =" << endl;
		if (&p == this) return *this;

		name = p.name;
		age = p.age;
		delete[] addr;
		addr = new char[strlen(p.addr) + 1];
		strcpy(addr, p.addr);
		return *this;
	}

	// move ������
	// �߿� !! : ��� ����� ���ؼ� move�� �Űܶ�!!
	People(People&& p) : name(std::move(p.name)), 
						 age(p.age), 
						 addr(p.addr)
	{
		cout << "move constructor" << endl;

		//addr = p.addr;
		p.addr = nullptr;

		p.age = 0;
	}






	People& operator=(People&& p)
	{
		cout << "move =" << endl;
		if (&p == this) return *this;

		name = std::move(p.name);
		age = p.age;

		delete[] addr;
		
		addr   = p.addr;
		p.addr = nullptr;
		p.age  = 0;

		return *this;
	}

};
int main()
{
	People p1("kim", 10, "seoul");
	People p2 = p1;	// ���� ������
	p2 = p1;		// ���� ���� ������

	People p3 = move(p1);	// move ������
	p3 = move(p2);			// move ���Կ�����


//	n = n;		// ok.. �����ؾ� �Ѵ�.
//	n = move(n); // undefined.. �̷���	 ������� ����� ��.
				// ����� �ٸ��� �ִ�.

}



