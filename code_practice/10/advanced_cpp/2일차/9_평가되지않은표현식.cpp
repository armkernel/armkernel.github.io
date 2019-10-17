// 9_평가되지않은표현식.  - 143 page
#include <iostream>
using namespace std;

/*
int foo(int a) 
{
	cout << "foo" << endl;
	return 0;
}
*/

// 평가되지 않은 표현식에서 사용할 함수는 선언만 있으면 된다.
int foo(int a);

int main()
{
	int n = 0;
	cout << sizeof( n )	<< endl;     // 4
	cout << sizeof( &foo ) << endl;  // 주소의 크기. 32bit환경 4
	//cout << sizeof( foo )  << endl;  // error. 함수의 크기는 구할수 없다
	cout << sizeof( foo(0) ) << endl;  // 함수 반환값의 크기. 4

	// unevaluated expression(평가되지 않은 표현식)
	// 함수 호출식이 실제로 함수를 호출하지 않는 것. 4개가 있다.
	
	sizeof(foo(0));		// 반환값 크기 4
	
	decltype( foo(0) ) n2; // 반환값과 동일 타입

	const type_info& r = typeid(foo(0));
	
	bool b = noexcept( foo(0) );
}


