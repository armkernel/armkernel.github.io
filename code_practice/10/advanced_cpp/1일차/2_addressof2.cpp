// 2_addressof1.cpp
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point* operator&() const
	{
		return nullptr; // C++11 ���ʹ� 0��� nullptr ���
	}
};
int main()
{
	const Point pt;
	
	const Point* p1 = reinterpret_cast<const Point*>(
		&reinterpret_cast<char&>(
			const_cast<Point&>(pt) ));

	cout << p1 << endl;
}



