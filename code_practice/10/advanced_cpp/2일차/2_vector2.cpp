#include <iostream>
using namespace std;

template<typename T> class vector
{
	T* buff;
	int sz;
public:
	vector(int s, T value = T()) :sz(s)
	{
		buff = static_cast<T*>(operator new(sizeof(T)*sz));

		try
		{
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

	//[] 연산자 재정의 : 객체를 배열 처럼 사용가능하게 한다.
	// 주의 v[0] = 100   처럼 함수 호출이 좌변이 되려면 참조 반환 필요
	T& operator[](int idx)
	{
		return buff[idx];
	}
};

int main()
{
	vector<int> v(10); 	
	v[0] = 100; // v.operator[](0) = 100
	cout << v[0] << endl;
}








