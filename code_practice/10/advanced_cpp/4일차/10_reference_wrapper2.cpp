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
//--------------------------
void foo(int& a) { a = 100; }

// bind 는 값으로 보관했다가 다시 호출할때 사용합니다.
template<typename T> void Bind(T arg)
{
	foo(arg);
}

// xreference_wrapper를 만드는 함수
template<typename T> 
xreference_wrapper<T> xref(T& obj)
{
	return xreference_wrapper<T>(obj);
}

int main()
{
	int n = 0;
	//Bind(&n); // T가 int* 인데 int& 로 변환될수 없다. error

//	xreference_wrapper<int> r(n);
//	Bind(r); // 결국 주소를 보내는것. 그런데, r은 int& 로 변환가능

//	Bind(xreference_wrapper<int>(n));

	Bind( xref(n) );

	cout << n << endl; // 100 

	double d;
	int n = d;

	Point pt;
	int n = pt; // pt.operator int()
	int& r = pt; // pt.operator int&()
}

