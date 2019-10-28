#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1(10);
	vector<bool> v2(10);

	auto a1 = v1[0];
	auto a2 = v2[0];

	cout << typeid(a1).name() << endl; // int
	cout << typeid(a2).name() << endl; // ?

	// 핵심	1.
	// modern effective-c++ : vector<bool> 이 반환하는 것은 bool 이 
	//				아니다.! auto 사용시 주의!!

	// 핵심 2. C++11 의 range -for 사용시 auto& 로 하면 에러가 나올수 있다.
	//			컨테이너가 temporary(rvalue)를 반환하는 경우가 있다.
	//          auto&& ( forwarding reference) 가 좋다.
	//for (auto& a : v1) // OK
	//for (auto& a : v2) // ERROR
	for (auto&& a : v2) // OK
		cout << a << endl;
}


