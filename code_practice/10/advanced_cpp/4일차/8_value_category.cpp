// 8_value_category
#include <iostream>
using namespace std;

struct Animal
{
	virtual void Cry() { cout << "Animal Cry" << endl; }  // 1
};
struct Dog : public Animal
{
	virtual void Cry() { cout << "Dog Cry" << endl; }  // 2
};
int main()
{
	Dog d;           d.Cry();  // 2
	Animal& a1 = d; a1.Cry();  // 2
	Animal  a2 = d; a2.Cry();  // 1
}





