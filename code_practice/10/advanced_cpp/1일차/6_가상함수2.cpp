// 6_가상함수1
#include <iostream>
using namespace std;

// 컴파일러는 컴파일 시에 모든 가상함수의 주소를 메모리에 보관해야 합니다

void* animal_table[] = { Animal_RTTI 정보, &Animal::Foo,
							&Animal::Goo, &Animal::Cry };

class Animal
{
	void* vtptr;
	int age;
public:
	Animal() : vtptr(animal_table) {}

	virtual void Foo() {}
	virtual void Goo() {}
	virtual void Cry() { cout << "1" << endl; }
};
//-------------------------------------------
void* dog_table[] = { Dog_RTTI 정보, &Animal::Foo,
							&Animal::Goo, &Cry::Cry };

class Dog : public Animal
{
	void* vtptr;
	int color;
public:
	Dog() : vtptr(dog_table) {}
	void Cry() { cout << "2" << endl; }
};

int main()
{
	Animal a; 
	Dog    d; 

	Animal* p = &d;

	p->Cry(); // p->vtptr[3](p); 라는 기계어 코드 생성
}
