#include <iostream>

using namespace std;

class Animal
{
  int age;
public:
  virtual void Cry() { cout << " Animal Cry! " << endl; }
};

class Dog : public Animal
{
  int color;
public:
  // override라고 칭함
  // 재정의할 때, 틀릴 수도 있으니 keyword를 붙일 수 있다. override를 붙여야함 
  void Cry() { cout << "Dog Cry" << endl; }
};

int main()
{
  Dog d;
  Animal* p = &d;

  p->Cry(); 
  // animal에 cry를 호출할지 dog의 cry를 호출할지..?
  // C++는 dog를 못부르고 animal을 부름.
  // c++도 dog께 오게 하려면 virtual을 만들면됨.
}
