// 4_EMPTY - 73 page
#include <iostream>
using namespace std;

// Empty 클래스 : non static member data 와 가상함수가 없는 클래스
class Empty {};

int main()
{
	Empty e;
	cout << sizeof(e) << endl; // 1

	// 핵심 : empty class 의 크기는 1 입니다.
}