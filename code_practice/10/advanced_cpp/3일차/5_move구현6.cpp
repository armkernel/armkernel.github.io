// 5_move����1
#include <iostream>
#include <string>
using namespace std;


// rule of 0

// �ڿ� ������ ���� �ϴ� �ڵ�� ������ ����.!!

// const char* => string
// int* buff   => vector
// �׷��� �����Ͱ� �ʿ� �ϸ� => ����Ʈ ������!

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



