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
			// buff �޸� ���� sz ���� ��ŭ�� value�� ä����(���������)
			// �����ϸ� ������ ���� �Ҹ��� ȣ���� ���� �߻�
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
// cppreference.com  ����  uninitialized_fill_n �˻��� ������.





int main()
{

	Point pt(0, 0);
	vector<Point> v(10, pt); // Point�� ����Ʈ �����ڰ� �����ϴ�.
}








