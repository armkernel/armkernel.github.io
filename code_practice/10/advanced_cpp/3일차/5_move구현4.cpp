// 5_move구현1
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


	// move 계열함수를 만들때
	// 1. 예외가 발생하지 않게 만들고
	// 2. 함수 () 뒤에 noxcept 를 적으세요

	// noexcept : 예외가 없다
	// noexcept(false) : 예외가 있다
	// noexcept(true) : 예외가 없다


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

	People p1 = p;       // 무조건 복사 생성자
	People p2 = move(p); // 무조건 move 생성자
	People p3 = move_if_noexcept(p2); // 예외가 없을때만 move
									  // 예외가 있으면 복사

	// move_if_noexcept 원리
	People p4 =
		is_nothrow_move_constructible<People>::value ? move(p3) : p3;





	vector<People> v(3, People("kim", 5, "seoul") ); 

	cout << "---------------" << endl;

	v.resize(5, People("kim", 5, "seoul"));

	cout << "---------------" << endl;
}



