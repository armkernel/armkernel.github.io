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
	~vector() { operator delete(buff); }

	// [] 연산자에서 각 비트를 반환하기 위해 만드는 "helper 클래스"
	class BitProxy
	{
		int* buff;
		int  idx;
	public:
		BitProxy(int* p, int n) : buff(p), idx(n) {}

		BitProxy& operator=(bool value)
		{
			// buff 주소의 idx 비트를 value 로 채웁니다.
			cout << idx << "비트 " << value << "채우기" << endl;
			return *this;
		}
		// 변환 연산자 함수
		operator bool()
		{
			// buff 에서 idx 번째 bit의 값 반환
			return true;
		}
	};	
	
	// 핵심 : Proxy 객체를 임시객체로 반환합니다.
	BitProxy operator[](int idx)
	{
		return BitProxy(buff, idx);
	}
};
int main()
{
	vector<bool> v2(30); // ?

	v2[10] = true; // BitProxy 에 = 연산자가 있어야 한다.

	bool n = v2[0]; // BitProxy 는 bool 로 암시적 변환이 되어야 한다.
					// 변환연산자 "operator bool()" 필요
	cout << n << endl; // 1
}








