#include <iostream>
using namespace std;

class Point
{
public:
	Point(int a, int b) {}
	Point(const Point& p) { cout << "copy" << endl; }
	Point(Point&& p)      { cout << "move" << endl; }
};

// 템플릿을 만들때 인자를 T& 로 할것인가 T&& 할것인가 ? 
// T& : lvalue 만 받겠다
// T&& : lvalue 와 rvalue 모두 받겠다
/*
template<typename T> T&& xmove(T&& arg)
{
	// xmove(lvalue) : T 는 int&
	// xmove(rvalue) : T 는 int
	// 즉 아래 캐스팅은 rvalue 캐스팅이 아닌 상황에 따라 달라지는 캐스팅
	return static_cast<T&&>(arg);
}
*/

template<typename T> remove_reference_t<T> && xmove(T&& arg)
//template<typename T> decltype(auto) xmove(T&& arg)
{
	return static_cast<remove_reference_t<T> &&>(arg);
}

int main()
{
	Point p1(1, 2);
	Point p2 = p1; // copy
	Point p3 = static_cast<Point&&>(p2); // move
	Point p4 = move(p3); // move
	Point p5 = xmove(Point(1,2)); // move


	// 아래 함수는 어떤 생성자를 호출할까요 ?
	// 1. 인자가 2개인생성자
	// 2. 복사 생성자
	// 3. move 생성자

	Point pt = Point(1, 2); //
	// C++98 : 임시객체를 만들고 복사 생성자로 pt에 복사
	// C++11 : 임시객체를 만들고 Move 생성자로 pt에 move
	//  하지만 많은 컴파일러가 최적화 하면서 복사 생성자, move생성자
	//  호출을 생략!!
	// C++17 : 문법적으로 임시객체를 만들지 않고 인자 2개 생성자호출

	// gcc a.cpp -std:c++98 -fno-elide-constructos
	// gcc a.cpp -std:c++17 -fno-elide-constructos
	// gcc a.cpp -std:c++11 -fno-elide-constructos

}


