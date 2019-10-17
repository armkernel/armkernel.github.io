// 3_traits1.cpp    - 115 page의 내용과 관련..
#include <iostream>
using namespace std;

// Traits(특질) : T(타입)의 다양한 속성을 조사하는 기술
template<typename T> void printv(T v)
{
	if ( T 가 포인터 라면 )
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}
int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}
