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

Dog d;

Animal   f1()   // 왼쪽에 올수없다. move 호출, non polynmorphic
{
	return d;
}
Animal&& f2()  // 왼쪽에 올수 없다. move 호출.  Polymorphic
{
	return move(d); 
}
Animal&  f3()   // 왼쪽에 올수있다. copy 호출, polymorphic
{
	return d;
}
int main()
{
	f2();

	f1().Cry(); // Animal Cry
	f2().Cry(); // Dog    Cry
	f3().Cry(); // Dog    Cry

	Dog d1 = f1(); // move
	Dog d2 = f2(); // move
	Dog d3 = f3(); // copy
}

// expression : 하나의 값으로 계산될수 있는 코드 모음

// lvalue : 표현식의 결과가 lvalue 참조
// xvalue : 표현식의 결과가 rvalue 참조
// prvalue : 표현식의 결과가 값(literal,임시객체)

f1();  // 값 반환
f2();  // rvalue 참조 반환
f3();  // lvalue 참조 반환

int main()
{
	int n = 10;
	static_cast<int&>(n) = 10; // 메모리가 반환. lvalue가능.
	static_cast<int&&>(n) = 10;// 메모리가 있지만, lvalue 안됨.
	n+1 = 10;					// 값(11)반환. lvalue 안됨.


	
	Point pt;

	// 아래 코드는 lvalue 를 _rvalue(xvalue)_ 로 캐스팅하고 있습니다.
	Point pt2 = static_cast<Point&&>(pt);
	
}





