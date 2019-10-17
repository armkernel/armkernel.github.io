#include <iostream>
#include <type_traits>
using namespace std;
// 안드로이드 소스 보세요
// github.com/asop-mirror   에서
// platform_system_core
// libutils/include/utils/typehelpers.h  
// copy_type 함수

template<typename T> void copy_type(T* dst, T* src, int sz)
{
	if ( is_trivially_copyable_v<T> )
	{
		cout << "복사 생성자가 하는일이 없으면 memcpy" << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		cout << "복사 생성자가 하는일이 있으면 모든 요소에 대해 복사"
				"생성자 호출" << endl;

		while (sz--)
		{
			new(dst) T(*src);
			++dst, ++src;
		}
	}
}

struct Point
{
	int x, y;

	// trivial : "하는일이 없다" 보다는 "하는일이 자명하다"!!
	//Point(const Point& p) : x(p.x), y(p.y) {}

	Point(const Point& p) = default;

	Point() = default;
};

int main()
{
//	char s1[10] = "hello";
//	char s2[10];
	//strcpy(s2, s1);
//	copy_type(s2, s1, 10);

	Point p1[10];
	Point p2[10];
	copy_type(p2, p1, 10);
}

