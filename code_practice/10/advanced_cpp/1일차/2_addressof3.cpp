// 2_addressof1.cpp
#include <iostream>
#include <functional>
using namespace std;


//std::reference_wrapper<int> w;


class Point
{
	int x, y;
public:
	Point* operator&() const
	{
		return nullptr; // C++11 부터는 0대신 nullptr 사용
	}
};

template<typename T> 
T* xaddressof(T& obj)
{
	// 아래 처럼 하면 안됩니다.
	// obj 가 const 일때 를 생각하고 const_cast를 생각해보세요
	//T* p = reinterpret_cast<T*>(
	//			&reinterpret_cast<char&>(
	//				const_cast<T&>(obj)));

	T* p = reinterpret_cast<T*>(      // const Point* 
									// 또는 Point* 로 변환
				&const_cast<char&>(   // const volatile 제거
				reinterpret_cast<const volatile char&>(obj)));
	return p;
}

int main()
{
	//const Point pt;
	Point pt;

	//const Point* p2 = xaddressof(pt);
	const Point* p2 = addressof(pt); // C++11 에서 추가된
									// 표준 함수..

	cout << p2 << endl;

//	const Point* p1 = reinterpret_cast<const Point*>(
//		&reinterpret_cast<char&>(
//			const_cast<Point&>(pt)));

//	cout << p1 << endl;
}



