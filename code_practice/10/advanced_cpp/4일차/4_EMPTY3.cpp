// 4_EMPTY - 73 page
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// STL 반복자

// 입력 반복자     : =*p, ++   싱글 패스만 보장
// 출력 반복자     : *p=, ++   싱글 패스만 보장
// 전진형 반복자   : =*p, ++,			=> 싱글리스트 반복자
// 양방향 반복자   : =*p, ++, --		=> 더블리스트 반복자
// 임의접근 반복자 : =*p, ++, --, +, -, []    => 연속된 메모리

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// find 알고리즘의 1,2번째 인자는 반복자 입니다.
	// 최소 요구조건을 말해 보세요 => 입력반복자
	auto p = find(v.begin(), v.end(), 3); 

	reverse(v.begin(), v.end()); // 양방향

	sort(v.begin(), v.end()); // 퀵 소트 알고리즘 - 
						// 임의 접근 반복자
	//---------------------------------
//	forward_list<int> s1 = { 1,2,3 }; // 싱글리스트
//	reverse(s1.begin(), s1.end()); // error

	list<int> s2 = { 1,2,3 };
	sort(s2.begin(), s2.end()); // ?

	s2.sort(); // ok.. 퀵이 아닌 다른 알고리즘.

	//vector<int> v2 = { 1,2,3,4 };
	//v2.sort(); // 이 멤버 함수가 있을까요 ? 없다

	sort()
}



