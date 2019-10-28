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

	//[] ������ ������ : ��ü�� �迭 ó�� ��밡���ϰ� �Ѵ�.
	// ���� v[0] = 100   ó�� �Լ� ȣ���� �º��� �Ƿ��� ���� ��ȯ �ʿ�
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








