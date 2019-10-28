// 2_addressof1.cpp
#include <iostream>
#include <functional>
using namespace std;


//std::reference_wrapper<int> w;


class Point
{
	int x, y;
public:
	Point* operator&() const
	{
		return nullptr; // C++11 ���ʹ� 0��� nullptr ���
	}
};

template<typename T> 
T* xaddressof(T& obj)
{
	// �Ʒ� ó�� �ϸ� �ȵ˴ϴ�.
	// obj �� const �϶� �� �����ϰ� const_cast�� �����غ�����
	//T* p = reinterpret_cast<T*>(
	//			&reinterpret_cast<char&>(
	//				const_cast<T&>(obj)));

	T* p = reinterpret_cast<T*>(      // const Point* 
									// �Ǵ� Point* �� ��ȯ
				&const_cast<char&>(   // const volatile ����
				reinterpret_cast<const volatile char&>(obj)));
	return p;
}

int main()
{
	//const Point pt;
	Point pt;

	//const Point* p2 = xaddressof(pt);
	const Point* p2 = addressof(pt); // C++11 ���� �߰���
									// ǥ�� �Լ�..

	cout << p2 << endl;

//	const Point* p1 = reinterpret_cast<const Point*>(
//		&reinterpret_cast<char&>(
//			const_cast<Point&>(pt)));

//	cout << p1 << endl;
}



