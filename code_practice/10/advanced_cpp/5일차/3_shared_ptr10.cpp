// 3_shared_ptr10
#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main()
{
	int* p1 = new int;

	// 아래 코드는 좋은 코드 일까요 ?
	shared_ptr<int> sp1(p1); // 관리객체 생성
	shared_ptr<int> sp2(p1); // 이순간, 또 다른 관리객체 생성!!

	// 핵심 : 자원을 획득한후에,, 자원의 포인터를 자원 관리객체에 넣지
	//		말라!!

	// 자원의 획득은 자원 관리 객체가 만들어 질때 동시에 해야 한다
	shared_ptr<int> sp3(new int); // 이렇게 하라는것
								// 물론, make_shared 가  더좋다

	// RAII : Resource Acquision Is Initialization
}



