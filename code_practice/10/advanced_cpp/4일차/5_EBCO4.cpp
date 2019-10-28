#include <iostream>
#include <type_traits>
using namespace std;

class Empty {};

// 아래 코드가 boost 라이브러리 안에 있는 compressed pair 라이브러리
// 입니다. www.boost.org

template<typename T, typename U, bool b = is_empty_v<T> > 
struct PAIR;
//{
//};
// 결국 위의 PAIR는 사용하지 않고, 조건에 따라(b값) 아래 2개를 사용한다.
// 이경우, primary template 의 구현없이 선언만 해도 됩니다.


// PAIR<int, int> p;

// 조건에 따라 PAIR를 부분 특수화 한다.
template<typename T, typename U> struct PAIR<T, U, false>
{
	T first;
	U second;
	PAIR() = default;

	template<typename A, typename B>
	PAIR(A&& a, B&& b) : first(std::forward<A>(a)),
		second(std::forward<B>(b))  {}

	T& getValue1() { return first; }
	U& getValue2() { return second; }
};

template<typename T, typename U> struct PAIR<T, U, true> : public T
{
	U second;

	PAIR() = default;

	template<typename A, typename B>
	PAIR(A&& a, B&& b) : T(std::forward<A>(a)),
		second(std::forward<B>(b)) {}

	T& getValue1() { return *this; }
	U& getValue2() { return second; }
};

int main()
{
	PAIR<Empty, int> p2;
	cout << sizeof(p2) << endl; // 4


	PAIR<int, int> p3; // ?
	cout << sizeof(p3) << endl; // 8
}



