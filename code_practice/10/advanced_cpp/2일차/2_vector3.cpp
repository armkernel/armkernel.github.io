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

// bool Ÿ���� ���� Ư��ȭ ( template specialization )
template<> class vector<bool> 
{
	int* buff;
	int sz;
public:
	vector(int s, bool value = false) :sz(s)
	{
		int cnt = (sz / 32) + 1;

		buff = static_cast<int*>(operator new(sizeof(int)*cnt));

		// buff ���� sz ��Ʈ�� value�� ä���..
	}
	~vector() { operator delete(buff);	}

	// �Ʒ� �ڵ� ��� �ұ�� ? �̷��� ����ϴ� ����� "temporary proxy"
	// 233 page ���
	?& operator[](int idx)
	{
		return buff[idx];
	}
};
int main()
{
//	vector<int>  v1(10); // sizeof(int) * 10 ��ŭ �޸� �Ҵ�
	vector<bool> v2(30); // ?

	v2[0] = 1;
}








