#include <iostream>
#include <type_traits>
using namespace std;
// �ȵ���̵� �ҽ� ������
// github.com/asop-mirror   ����
// platform_system_core
// libutils/include/utils/typehelpers.h  
// copy_type �Լ�

template<typename T> void copy_type(T* dst, T* src, int sz)
{
	if ( is_trivially_copyable_v<T> )
	{
		cout << "���� �����ڰ� �ϴ����� ������ memcpy" << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		cout << "���� �����ڰ� �ϴ����� ������ ��� ��ҿ� ���� ����"
				"������ ȣ��" << endl;

		while (sz--)
		{
			new(dst) T(*src);
			++dst, ++src;
		}
	}
}

struct Point
{
	int x, y;

	// trivial : "�ϴ����� ����" ���ٴ� "�ϴ����� �ڸ��ϴ�"!!
	//Point(const Point& p) : x(p.x), y(p.y) {}

	Point(const Point& p) = default;

	Point() = default;
};

int main()
{
//	char s1[10] = "hello";
//	char s2[10];
	//strcpy(s2, s1);
//	copy_type(s2, s1, 10);

	Point p1[10];
	Point p2[10];
	copy_type(p2, p1, 10);
}

