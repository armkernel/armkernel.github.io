#include <iostream>
using namespace std;

// const_cast : 동일 타입 객체의 const, volatile 속성
//				제거.

int main()
{
	const int c = 10;

	int* p1 = &c; // error
	int* p1 = (int*)&c; // ok
	int* p1 = static_cast<int*>(&c); // error
	int* p1 = reinterpret_cast<int*>(&c); // error
	int* p1 = const_cast<int*>(&c); // ok.

	volatile int n = 10;
	int* p2 = &n; // error
	volatile int* p2 = &n; // ok..

	int* p2 = const_cast<int*>(&n); //ok

}

// 아래 코드 해결해 보세요
int main()
{
	const int c = 10;

	// c의 주소를 p에 담아 보세요..
	// 단, C++ 캐스팅 사용
	//char* p = &c ; // error
	char* p = reinterpret_cast<char*>(&c); // error
								// const 제거 안됨.
	char* p = const_cast<char*>(&c);// error. 다른 타입

	char* p = reinterpret_cast<char*>(
					const_cast<int*>(&c));//ok

	char* p = (char*)&c ; // ok.

}




