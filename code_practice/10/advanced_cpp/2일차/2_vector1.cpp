#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b)
	{
		cout << "Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
};

template<typename T> class vector
{
	T* buff;
	int sz;
public:
	vector(int s, T value = T()) :sz(s)
	{
		buff = static_cast<T*>(operator new(sizeof(T)*sz));

		/*
		int cnt = 0;
		try
		{
			for (int i = 0; i < sz; i++)
			{
				new(&buff[i]) T(value); 
				cnt = i;
			}
		}
		catch (...)
		{
			for (int i = 0; i <= cnt; i++)
				buff[i].~T();

			operator delete(buff);
		}
		*/

		try
		{
			// buff 메모리 부터 sz 갯수 만큼을 value로 채워라(복사생성자)
			// 실패하면 성공한 것은 소멸자 호출후 예외 발생
			std::uninitialized_fill_n(buff, sz, value);
		}
		catch (...)
		{
			operator delete(buff);
		}
	}
	~vector()
	{
		for (int i = 0; i < sz; i++)
			buff[i].~T();
		operator delete(buff);
	}
};
// cppreference.com  에서  uninitialized_fill_n 검색해 보세요.





int main()
{

	Point pt(0, 0);
	vector<Point> v(10, pt); // Point는 디폴트 생성자가 없습니다.
}








