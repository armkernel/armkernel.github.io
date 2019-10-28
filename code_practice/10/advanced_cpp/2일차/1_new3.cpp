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

// ���� 103 page ���� - container ���鶧 ���� ����
template<typename T> class vector
{
	T* buff;
	int sz;
public:
	// T() : zero initialization
	// T�� primitive �Ǵ� ������ : 0
	//     user type �̸� ����Ʈ ������
	vector(int s, T value = T() ) :sz(s)
	{
		//buff = new T[sz]; // �̷��� ���� ���ڴ� ��.!!
						 // T �� ����Ʈ �����ڰ� �־�� �Ѵٴ� ������ ����.

		buff = static_cast<T*>(operator new(sizeof(T)*sz));

		int cnt = 0;
		try
		{
			// �Ҵ�� �޸𸮿� ������ ȣ��
			for (int i = 0; i < sz; i++)
			{
				//new(&buff[i]) T; // ����Ʈ ������
				new(&buff[i]) T(value); // ���� ������
				cnt = i;
			}
		}
		catch (...)
		{
			// ������ ȣ�⿡ ������ ��ü�� �ٽ� �Ҹ��� ȣ��
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
	vector<Point> v(10, pt); // Point�� ����Ʈ �����ڰ� �����ϴ�.
}








