// 1_캐스팅1.cpp  - 7 page addressof 관련 주제

// C 캐스팅의 문제점
// 위험한 캐스팅도 거의 다 허용한다.
// 버그의 원인이 된다.
// 그래서 C++은 4개의 캐스팅을 제공한다.
#include <iostream>
using namespace std;

int main()
{
	//const int c = 10; // 컴파일 할때 c가 10이라는 사실을 안다.
						// 매크로 처럼 치환 되는 경우가 많다.

	int n = 10;
	const int c = n; // 컴파일 할때 값을 알수 없다.

	//int* p = &c; // error. 상수의 주소를 비상수를 가리키는포인터
				// 에 담을수 없다.
	
	int* p = (int*)&c; // C 스타일 명시적 캐스팅. ok

	*p = 20;

	cout << c << endl; // ?? 예측해 보세요  10   20
	cout << *p << endl; // 20					20
}



/*
int main()
{
	int n = 10;

	//double* p = &n; // C언어는 암시적 변환 허용, 단, 경고 발생
					// C++언어 암시적 변환 안됨. error

	double* p = (double*)&n; // ok. C 스타일 명시적 변환은 허용

	*p = 3.4; // !!
}
*/
