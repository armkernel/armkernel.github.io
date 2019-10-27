#include <iostream>

using namespace std;

class Animal
{
  int age;
};

class Dog : public Animal
{
  int color;
};


int main()
{
  Dog d;
  Dog* p1 = &d;

  double* p2 = &d;

  Animal* p3 = &d;
}


