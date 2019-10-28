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

	T& operator[](int idx)
	{
		return buff[idx];
	}
};

// bool 타입을 위한 특수화 ( template specialization )
template<> class vector<bool> 
{
	int* buff;
	int sz;
public:
	vector(int s, bool value = false) :sz(s)
	{
		int cnt = (sz / 32) + 1;

		buff = static_cast<int*>(operator new(sizeof(int)*cnt));

		// buff 부터 sz 비트를 value로 채우기..
	}
	~vector() { operator delete(buff);	}

	// 아래 코드 어떻게 할까요 ? 이럴때 사용하는 기술이 "temporary proxy"
	// 233 page 기술
	?& operator[](int idx)
	{
		return buff[idx];
	}
};
int main()
{
//	vector<int>  v1(10); // sizeof(int) * 10 만큼 메모리 할당
	vector<bool> v2(30); // ?

	v2[0] = 1;
}








