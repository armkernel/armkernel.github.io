#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void foo(T a)
{
	// T의 포인터 여부에 따라 다른일 하기
	// if 문
	if (is_pointer<T>::value)
	{
		// ...
		// 단, "*a = 10" 등의 코드는 사용할수 없다.
	}
	else
	{
		// ...
	}
	// "*a = 10" 를 사용하고 싶다면

	// 1. if constexpr 사용 - 해결책 1. 참고
	if constexpr (is_pointer<T>::value)
	{
		*a = 10; // ok!!!
	}
	else 
	{
	}
	// 2. true_type, false_type 으로 오버로딩

	foo_imp(a, is_pointer<T>());
}
template<typename T> void foo_imp(T a, true_type) {}  // *a = 10가능
template<typename T> void foo_imp(T a, false_type) {}

// 3. 함수 템플릿을 2개 만들고 enable_if 로 조건에 따라 사용하도록
template<typename T> 
typename enable_if<is_pointer<T>::value>::type
foo(T a)
{
}

template<typename T>
typename enable_if< !is_pointer<T>::value >::type
foo(T a)
{
}
// 기술이 나온 순서
// 2번의 true_type/false_type   - 3개의 함수
// 3번의 enable_if				- 2개의 함수
// 1번의 if constexpr			- 1개의 함수안에서.

// github.com/aosp-mirrow
// platform_system_core (2page)
// libutils/include/utils/typehelpers.h 안에 copy_type






