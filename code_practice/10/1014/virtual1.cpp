#include <iostream>

using namespace std;

class Animal
{
public:
  void cry() { cout << "1" << endl; }
};

class Dog : public Animal
{
public:
  void cry() { cout << "2" << endl; }
};

int main()
{
  Animal a; a.cry();
  Dog d; d.cry();

  Animal* p = &d;
  p->cry();
}
