// 7_unique_ptr8
#include <iostream>
#include <memory>
using namespace std;

int main()
{
	unique_ptr<int> up1(new int);
	unique_ptr<int[]> up2(new int[10]); // C++14

	// 에러는 모두 골라 보세요
	*up1 = 10;    // ok
//	up1[0] = 10;  // error

//	*up2 = 10;    // error
	up2[0] = 10;  //ok

	// 다음중 에러를 모두 골라 보세요.
	shared_ptr<int> sp(new int);
	unique_ptr<int> up(new int);

	shared_ptr<int> p1 = up;		// error
	shared_ptr<int> p2 = move(up);	// ok
	unique_ptr<int> p3 = sp;		// error
	unique_ptr<int> p4 = move(sp);  // error
}

// * 대신 스마트 포인터를 사용하고 싶습니다
// 아래 함수의 반환타입을 뭘로 할까요 ? shared ? unique ?
//shared_ptr<int> AllocBuffer(int size)
unique_ptr<int> AllocBuffer(int size)
{
	return unique_ptr<int>(new int);
}
shared_ptr<int> ret1 = AllocBuffer(100);	
unique_ptr<int> ret2 = AllocBuffer(100);


int[3] a; // a의 타입은 int[3];
int[4] a; // a의 타입은 int[4];

//int[] : unknown size array type.. 이라는 이름을 가진 타입!!
			// incomplete type 이므로 이 타입의 객체는 만들수 없습니다.

//void foo(int[] arg) // 주의 unknown size arraY 아닙니다.
					// int* 입니다.
// C++ 표준 스마트 포인터 : shared_ptr, weak_ptr, unique_ptr

int main()
{
	int n = 0;
	int* p = &n; // p를 스마트 포인터로 변경할수 있을까요 ?
	shared_ptr<int> p (&n);

//	observer_ptr<int> p(&n); // C++20
}
// cafe.naver.com/cppmaster 에 cppmaster.h 받아 놓으세요..



 


