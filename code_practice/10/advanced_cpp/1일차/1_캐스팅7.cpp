// 1_캐스팅7.cpp
#include <iostream>
using namespace std;

class Animal
{
public:
	// 가상함수가 있으면
	// 가상함수 테이블이 만들어 지고, 그안에 타입 정보가 같이
	// 놓이고,
	// 각 객체가 테이블을 가리키게 됩니다.

	// 결론 :가상함수가 없는 객체는 dynamic_cast를 사용할수
	//			없습니다.
	virtual ~Animal() {}
};

class Dog : public Animal
{
public:
	void Cry() {}
};
//---------------------
void foo(Animal* p)
{
	// 혹시 p가 Dog 라면 아래 처럼 하고 싶다.
	//p->Cry(); // error

	// Down Casting : 기반 타입을 => 파생 타입으로 변경
	//Dog* pDog = static_cast<Dog*>(p); // 컴파일 : ok.
									  // 항상 캐스팅 성공

	// p 가 정말 Dog 일때만 성공해야 한다.
	// 컴파일 시간이 아닌 실행시간에 조사한후 캐스팅
	Dog* pDog = dynamic_cast<Dog*>(p);

	cout << pDog << endl;
}
int main()
{
	Animal a; foo(&a);
	Dog    d; foo(&d);
}

// C++ 캐스팅

// static_cast   - 컴파일 
 
// reinterpret_cast - 컴파일

// const_cast	- 컴파일 

// dynamic_cast - 실행시간(오버헤드 있음)





