// 4_�������1
#include <iostream>
using namespace std;

class Car
{
	int speed;
public:
	~Car() { cout << "Car �ı�" << endl; }
};
Car* p;

void foo()
{
	Car* p1 = new Car;
	p = p1;
	// p1�� �ʿ� ����. �ı��ص� �ɱ�?
	delete p1;
}
int main()
{
	foo();
}