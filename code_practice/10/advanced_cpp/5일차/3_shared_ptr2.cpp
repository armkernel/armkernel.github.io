#include <iostream>
#include <memory>
#include <Windows.h>
using namespace std;

class Point
{
public:
	Point()  { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

void foo(void* p) { cout << "foo" << endl; free(p); }
int main()
{
	// 삭제자 변경
	shared_ptr<int>  p1(new int);          // p1 소멸자에서 delete
	shared_ptr<void> p2(malloc(100), foo); // 소멸자에서 foo 호출
	shared_ptr<void> p3(malloc(100), free);
	shared_ptr<void> p4(malloc(100), [](void* p) { free(p); } );

	// 배열 모양으로 할당
	//shared_ptr<int> p5(new int[10]); // 버그.. delete[] 가 필요
	shared_ptr<int> p6(new int[10], [](int* p) {delete[] p; });

	// default_delete<int> : delete    를 수행하는 함수 객체
	// default_delete<int[]> : delete[]
	shared_ptr<int> p7(new int[10], default_delete<int[]>() );

	// 공식적으로는 C++17 에서 부터 지원
	shared_ptr<int[]> p8(new int[10] );

	shared_ptr<Point[]> p9(new Point[3]);

//	Point* pt = new Point[3]; // 생성자 3번 호출
//	delete pt; // 소멸자 한번 호출

	// 
	shared_ptr< FILE > sp1(fopen("a.txt", "wt"), fclose );

	HANDLE h = CreateEvent(0, 0, 0, 0);
	CloseHandle(h);

	//shared_ptr< remove_pointer<HANDLE>::type > sp2(CreateEvent(0, 0, 0, 0), CloseHandle);
}







