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

// 교재 103 page 주제 - container 만들때 주의 사항
template<typename T> class vector
{
	T* buff;
	int sz;
public:
	// T() : zero initialization
	// T가 primitive 또는 포인터 : 0
	//     user type 이면 디폴트 생성자
	vector(int s, T value = T() ) :sz(s)
	{
		//buff = new T[sz]; // 이렇게 하지 말자는 것.!!
						 // T 는 디폴트 생성자가 있어야 한다는 제약이 생김.

		buff = static_cast<T*>(operator new(sizeof(T)*sz));

		int cnt = 0;
		try
		{
			// 할당된 메모리에 생성자 호출
			for (int i = 0; i < sz; i++)
			{
				//new(&buff[i]) T; // 디폴트 생성자
				new(&buff[i]) T(value); // 복사 생성자
				cnt = i;
			}
		}
		catch (...)
		{
			// 생성자 호출에 성공한 객체는 다시 소멸자 호출
			for (int i = 0; i <= cnt; i++)
				buff[i].~T();

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






int main()
{
//	vector<int> v(10);

	Point pt(0, 0);
	vector<Point> v(10, pt); // Point는 디폴트 생성자가 없습니다.
}








