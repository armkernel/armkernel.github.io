// 6_move_주의사항1
#include <iostream>
#include <string>
using namespace std;

// STL 의 pair 와 유사한 클래스를 만들어 봅시다.
template<typename T, typename U> struct PAIR
{
	T first;
	U second;
	PAIR() = default;

	// 인자 2개 짜리 생성자 만들어서 first, second 초기화 해보세요
	PAIR( const T& a,  const U& b) : first(a), second(b) {}

	PAIR(T&& a, U&& b) : first(move(a)), second(move(b)) {}

	// C++11 이전 : 생성자(함수 인자)로 const T& 를 주로 사용

	// C++11 이후 - move지원을 위해 2개의 생성자를 만드세요
	// 1. const T&
	// 2. rvalue reference 버전 - move를 위해!

};
int main()
{
	PAIR<int, int> p1(3, 4);
	string s1 = "hello";
	string s2 = "world";
	PAIR<string, string> p2(s1, s2);

	PAIR<string, string> p3(move(s1), move(s2));

	cout << s1 << endl; // 

	string s1 = "hello";
	string&& s2 = move(s1); // static_cast<string&&>(s1)
	string s3 = move(s2);
}




