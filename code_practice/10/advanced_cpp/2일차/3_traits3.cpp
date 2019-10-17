#include <iostream>
using namespace std;
// T가 포인터 인지를 조사하는 기술
// 1. 구조체 템플릿을 만든다.
// 2. static constexpr bool value를 넣고 false 로 초기화
// 3. 해당 조건을 만족하는 부분특수화 버전을 만들고 value = true로 변경

template<typename T> struct xis_reference
{
	static constexpr bool value = false;
};
template<typename T> struct xis_reference<T&>
{
	static constexpr bool value = true;
};
template<typename T> struct xis_reference<T&&>
{
	static constexpr bool value = true;
};

// ::value 는 보기 좋지 않다.
// C++14 의 variable template 문법 사용
template<typename T> 
bool xis_reference_v = xis_reference<T>::value;

int main()
{
	// xis_referenence 만들어 보세요. xis_pointer를 보고 잘생각해보세요
	cout << xis_reference<int>::value << endl; // false
	cout << xis_reference<int&>::value << endl; // true
	cout << xis_reference_v<int&> << endl; // true
}

//--------------------------------------
/*
template<typename T> class list {};       // 클래스 템플릿
template<typename T> void foo(T a) {};    // 함수 템플릿
template<typename T> using List = list<T>;// using 템플릿
List<int> s; // == list<int>

template<typename T> bool v = xis_pointer<T>::value;  // variable template
v<int> // =xis_pointer<int>::value
v<int*>
v<int>
*/