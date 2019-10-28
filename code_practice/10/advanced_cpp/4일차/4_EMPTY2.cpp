// 4_EMPTY - 73 page
#include <iostream>
#include <vector>
#include <list>
using namespace std;

// STL 반복자

// 입력 반복자     : =*p, ++   싱글 패스만 보장
// 출력 반복자     : *p=, ++   싱글 패스만 보장

// 아래 3개는 멀티 패스 보장
// 전진형 반복자   : =*p, ++,			=> 싱글리스트 반복자
// 양방향 반복자   : =*p, ++, --		=> 더블리스트 반복자
// 임의접근 반복자 : =*p, ++, --, +, -, []    => 연속된 메모리


int main()
{
	//vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	list<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = v.begin();

	// 반복자 p 를 5칸 전진해 보세요
	p = p + 5;  // 좋지 않은 코드..

	cout << *p << endl; // 6
}