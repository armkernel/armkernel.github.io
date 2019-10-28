// 11_MemberDetect
#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

class Test
{
public:
	Test(int n) {}
	void resize(int n) {}
};
// cppreference.com 에서 allocator 검색

template<typename T> T xdeclval(); // 핵심. 구현이 없습니다.
				// 정확히는 T&& 


template<typename U> struct has_resize_function
{
	typedef char YES[1]; 
	typedef char NO[2];


	template<typename T> 
	//static YES&   check( decltype( T().resize(0) )*  n );

	static YES&   check(decltype( xdeclval<T>().resize(0))*  n);


	template<typename T> static NO&  check(...);

	static constexpr bool value =
		(sizeof(check<U>(0)) == sizeof(YES));
};

int main()
{
	cout << has_resize_function< vector<int> >::value << endl; // 1

	cout << has_resize_function<Test>::value << endl; // 0
}



