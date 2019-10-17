// 10_reference_wrapper1.cpp
#include <iostream>
#include <functional>
using namespace std;

// C++ 참조 : 한번 가리킨 메모리는 변경할수 없다. 일종의 상수
//			 대입 연산시 값이 이동한다.
// reference_wrapper : 이동 가능한 참조.. 대입연산시 참조가 이동

// 결국 "1. 주소를 보관"   "2. 진짜 참조타입으로 변환가능"
template<typename T> struct xreference_wrapper
{
	T* obj;
public:
	xreference_wrapper(T& r) : obj(&r) {}

	// 진짜 참조와 호환되어야 한다.
	operator T&() { return *obj; }
};

int main()
{
	int n1 = 10;
	int n2 = 20;

//	int& r1 = n1;
//	int& r2 = n2;

	xreference_wrapper<int> r1 = n1;
	xreference_wrapper<int> r2 = n2;

	r1 = r2;

	int& r3 = r1;

	// 결과 예측해 보세요
	cout << n1 << endl;
	cout << n2 << endl;
	cout << r1 << endl;
	cout << r2 << endl;
}