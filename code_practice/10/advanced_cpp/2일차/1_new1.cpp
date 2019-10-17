// github.com/aosp-mirror
// platform_system_core  - 2번째 page에 있습니다.
// libutils/include/utils/typehelpers.h
// "copy_type" 함수 2개
// 1_new1.cpp  - 103 page ~
//               104 page중간에 construct() 함수내용 

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) 
	{
		cout << "Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl;	}
};
int main()
{
	// 1. 메모리 할당
	// 2. 생성자 호출
	//Point* p1 = new Point(1, 2);

	// 1. 소멸자 호출
	// 2. 메모리 해지
	//delete p1;

	// 메모리 할당과 생성자 호출의 분리
	// 1. 메모리만 할당 ( C 의 malloc 과 유사)
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point)));
	cout << p2 << endl;

	// 2. 할당된 메모리에 생성자 호출 - Placement new 라는 기술
	// new Point(1, 2);    // 메모리할당 + 생성자 호출
	new(p2) Point(1, 2);// 이미존재하는 메모리(p2)에 생성자 호출  

	//p2->Point(1, 2); // 이렇게 되면 좋을거 같지만.. error

	// 3. 소멸자만 호출
	p2->~Point(); // 메모리 해지 없이 소멸자 호출


	// 4. 소멸자 호출없이 메모리만 해지
	//delete p2; // 소멸자 호출 + 메모리 해지
	operator delete(p2); // 메모리만 해지
}


