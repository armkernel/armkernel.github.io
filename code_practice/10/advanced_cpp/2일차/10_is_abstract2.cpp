#include <iostream>
#include <type_traits>
using namespace std;

class Shape
{
	virtual void Draw() = 0;
};

// 1. 조건을 만족하는 경우만 만족하지 않은 경우에 다른 함수가 호출되도록한다.
// 추상 클래스
// 객체는 만들수 없다.
// 포인터 변수는 만들수 있다.
// 배열을 가리키는 포인터는 만들수 없다.

// 2. 어떤 함수가 선택되는지 확인만 하면 된다 "평가되지 않은 표현식"

template<typename T> char check(T(*)[1]);
template<typename T> int  check(...);

int main()
{
	if ( sizeof(check<Shape>(0) ) == sizeof(char))
		cout << "추상아님.." << endl;
	else 
		cout << "추상..." << endl;
}



