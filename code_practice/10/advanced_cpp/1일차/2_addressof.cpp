// 2_addressof1.cpp
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point* operator&() const
	{
		return nullptr; // C++11 부터는 0대신 nullptr 사용
	}
};
int main()
{
	Point pt;
	cout << &pt << endl; // pt.operator&()

	// pt의 주소를 구해 봅시다.
	Point* p1 = &pt; // 실패 .. 0

	// step1. char* 타입에 담아 보자
	//char* p2 = reinterpret_cast<char*>(&pt); // &pt이므로
								// operator& 호출.  0. 실패

	//char* p2 = &reinterpret_cast<char>(pt);
				// 문제점 1. reinterpret_cast는 값 캐스팅 안됨
				//       2. 값 캐스팅은 임시객체를 만들게된다.
	char* p2 = &reinterpret_cast<char&>(pt); // ok..
	

	// step 2. Point 타입에 담기

	Point* p3 = reinterpret_cast<Point*>(
					&reinterpret_cast<char&>(pt)); 

	cout << p3 << endl; // ok.
}



