#include <iostream>
using namespace std;

// T가 포인터 인지를 조사하는 기술
// 1. 구조체 템플릿을 만든다.
// 2. enum 상수 value를 넣고 false 로 초기화
// 3. 해당 조건을 만족하는 부분특수화 버전을 만들고 value = true로 변경

template<typename T> struct xis_pointer
{
	//enum { value = false }; // C++11 이전 스타일
	static constexpr bool value = false; // C++11 스타일
};

template<typename T> struct xis_pointer<T*>
{
	// enum { value = true };
	static constexpr bool value = true;
};

template<typename T> void foo(T a)
{
	if (xis_pointer<T>::value)
		cout << "포인터 입니다." << endl;
	else
		cout << "포인터 아님" << endl;
}

int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}
