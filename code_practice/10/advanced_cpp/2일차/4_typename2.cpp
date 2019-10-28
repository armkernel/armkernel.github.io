#include <iostream>
#include <vector>
using namespace std;
/*
template<typename T> class vector
{
public:
	typedef unsigned int size_type; // 크기를 저장하는 타입
	size_type size() const { return 10; }
};
*/

//void foo(vector<int>& v)
template<typename T> void foo(T& v)
{
	// ?에 들어갈 최고의 선택은 무슨 타입일까요 ?
	//unsigned int n = v.size();
	//vector<int>::size_type n = v.size(); // 최고의 코드.

	typename T::size_type n = v.size(); // 최고의 코드.
}

// cppreference.com 에서 vector 검색해 보세요

int main()
{
	vector<int> v(10);
	foo(v);
}