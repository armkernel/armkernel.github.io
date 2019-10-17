#include <iostream>
#include <type_traits>
using namespace std;

class Shape
{
		virtual void Draw() = 0;
};


template<typename U> struct xis_abstract
{
	typedef char YES[1]; // 143p ���� ���� �ֽ��ϴ�.
	typedef char NO[2];   

	template<typename T> static NO&   check(T(*)[1]);
	template<typename T> static YES&  check(...);

	static constexpr bool value = 
		( sizeof(check<U>(0)) == sizeof(YES) );
};

int main()
{
	cout << xis_abstract<Shape>::value << endl;
}



