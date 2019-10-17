// 5_move구현1
#include <iostream>
#include <string>
using namespace std;


// rule of 0

// 자원 관리는 직접 하는 코드는 만들지 말자.!!

// const char* => string
// int* buff   => vector
// 그래도 포인터가 필요 하면 => 스마트 포인터!

class People
{
	string name;
	int    age;
	//char*  addr;
	string addr;
public:
	People(string n, int a, string ad) : name(n), age(a), addr(ad)
	{
	}
};


int main()
{
	People p("kim", 5, "seoul");

}



