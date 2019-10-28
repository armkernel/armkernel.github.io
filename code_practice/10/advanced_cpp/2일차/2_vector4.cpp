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
	~vector() { operator delete(buff); }

	// [] �����ڿ��� �� ��Ʈ�� ��ȯ�ϱ� ���� ����� "helper Ŭ����"
	class BitProxy
	{
		int* buff;
		int  idx;
	public:
		BitProxy(int* p, int n) : buff(p), idx(n) {}

		BitProxy& operator=(bool value)
		{
			// buff �ּ��� idx ��Ʈ�� value �� ä��ϴ�.
			cout << idx << "��Ʈ " << value << "ä���" << endl;
			return *this;
		}
		// ��ȯ ������ �Լ�
		operator bool()
		{
			// buff ���� idx ��° bit�� �� ��ȯ
			return true;
		}
	};	
	
	// �ٽ� : Proxy ��ü�� �ӽð�ü�� ��ȯ�մϴ�.
	BitProxy operator[](int idx)
	{
		return BitProxy(buff, idx);
	}
};
int main()
{
	vector<bool> v2(30); // ?

	v2[10] = true; // BitProxy �� = �����ڰ� �־�� �Ѵ�.

	bool n = v2[0]; // BitProxy �� bool �� �Ͻ��� ��ȯ�� �Ǿ�� �Ѵ�.
					// ��ȯ������ "operator bool()" �ʿ�
	cout << n << endl; // 1
}








