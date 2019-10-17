// 5_move����1
#include <iostream>
#include <string>
using namespace std;


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


	// move �迭�Լ��� ���鶧
	// 1. ���ܰ� �߻����� �ʰ� �����
	// 2. �Լ� () �ڿ� noxcept �� ��������

	// noexcept : ���ܰ� ����
	// noexcept(false) : ���ܰ� �ִ�
	// noexcept(true) : ���ܰ� ����


	//People(People&& p) noexcept 
	People(People&& p) noexcept( 
				is_nothrow_move_constructible<string>::value )

		: name(std::move(p.name)),
		age(p.age),
		addr(p.addr)
	{
		cout << "move constructor" << endl;
		p.addr = nullptr;
		p.age = 0;
	}

	   	  
	People& operator=(People&& p) noexcept
	{
		cout << "move =" << endl;
		if (&p == this) return *this;

		name = std::move(p.name);
		age = p.age;

		delete[] addr;

		addr = p.addr;
		p.addr = nullptr;
		p.age = 0;

		return *this;
	}
};

#include <vector>

int main()
{
	People p("kim", 5, "seoul");

	People p1 = p;       // ������ ���� ������
	People p2 = move(p); // ������ move ������
	People p3 = move_if_noexcept(p2); // ���ܰ� �������� move
									  // ���ܰ� ������ ����

	// move_if_noexcept ����
	People p4 =
		is_nothrow_move_constructible<People>::value ? move(p3) : p3;





	vector<People> v(3, People("kim", 5, "seoul") ); 

	cout << "---------------" << endl;

	v.resize(5, People("kim", 5, "seoul"));

	cout << "---------------" << endl;
}



