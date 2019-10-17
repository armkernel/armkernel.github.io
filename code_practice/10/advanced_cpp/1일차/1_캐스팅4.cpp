#include <iostream>
using namespace std;

struct A { int a; };
struct B { int b; };
struct C : public A, public B { int c; };

int main()
{
	C ccc;  // 메모리 모양 생각해보세요..
	A* pA = &ccc; // 1000
//	B* pB = &ccc; // 1004
//	B* pB = (B*)&ccc; // 1004
	
	B* pB = static_cast<B*>(&ccc); // 1004
					// &ccc 주소에서 B의 위치를 찾아서 주소 반환
					// 해당 주소에 B가 없으면 연관성이 없으므로
					// 에러..
					// 컴파일 시간에 수행
					// &ccc + sizeof(A) 

	B* pB = reinterpret_cast<B*>(&ccc); // 1000
					// &ccc 주소를 무조건 B 처럼 생각
					// 연관성 필요 없다. 컴파일 시간..

	pB->b = 100; // ccc.a 에 넣기.



	cout << &ccc << endl; // 1000 이라고 가정할때
	cout << pA   << endl; // 예측해 보세요
	cout << pB   << endl; // 예측해 보세요

}




