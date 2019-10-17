#include <iostream>
using namespace std;

// reinterpret_cast
// 1. 서로 다른 타입의 주소를 캐스팅
// 2. 정수 <=> 포인터   캐스팅
// 3. 서로 다른 타입을 참조 형식으로 캐스팅


int main()
{
	double d = 3.4;

	int* p1 = (int*)&d; // ok. 하지만 실수 인지 의도인지 알수 없다
	int* p2 = static_cast<int*>(&d); // error
	int* p3 = reinterpret_cast<int*>(&d); // ok

	// 정수 => 포인터로 변환
	int* p4 = 10; //error
	int* p4 = (int*)10; //ok
	int* p4 = static_cast<int*>(10); // error
	int* p4 = reinterpret_cast<int*>(10); // ok

}




