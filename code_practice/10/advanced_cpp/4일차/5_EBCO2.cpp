#include <iostream>
using namespace std;

class Empty {};


template<typename T, typename U> struct PAIR
{
	T first;
	U second;
	PAIR() = default;

	template<typename A, typename B> 
	PAIR(A&& a, B&& b) : first( std::forward<A>(a)), 
						 second( std::forward<B>(b))
	{
	//	first = std::forward<A>(a);
	//	second = std::forward<B>(b);
	}
	T& getValue1() { return first; }
	U& getValue2() { return second; }
};

int main()
{
	PAIR<int, int> p(3, 4);
	
	PAIR<Empty, int> p2;
	cout << sizeof(p2) << endl;
}



