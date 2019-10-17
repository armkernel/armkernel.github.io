// 4_참조계수1
#include <iostream>
using namespace std;

class Car
{
	int speed;
public:
	~Car() { cout << "Car 파괴" << endl; }
};
Car* p;

void foo()
{
	Car* p1 = new Car;
	p = p1;
	// p1이 필요 없다. 파괴해도 될까?
	delete p1;
}
int main()
{
	foo();
}