#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	//vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	list<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = v.begin();
	++p; // 좋은 코드 - 모든 반복자는 ++이 가능하다

	//p = p + 5;  // 좋지 않은 코드 - 임의접근 반복자만 가능
				// list 반복자는 + 연산안됨.

	advance(p, 5); // p가 임의접근 이면 : p = p +5
					//    아니면 ++p 를 5번

	cout << *p << endl; 
}