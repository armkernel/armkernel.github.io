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
int main()
{
	// Point ��ü�� ���� �Ѱ� �����
	Point* p1 = new Point(0, 0);

	// ���� 10�� ����� ������!!
	//Point* p2 = new Point[10]; // error.

	// ����Ʈ �����ڰ� ���� ��ü�� ������ �����Ϸ��� 
	// �޸� �Ҵ�� ������ ȣ���� �и��ϸ� �˴ϴ�.
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	// 10���� �޸� ������ ������ ȣ��
	for (int i = 0; i < 10; i++)
		new(&p2[i]) Point(0, 0);

	//delete [] p2;  // �̷��� ��������.. �Ʒ� ó�� �и��ϼ���

	// ����Ŀ��� �Ҹ��� ȣ��
	for (int i = 0; i < 10; i++)
		p2[i].~Point();

	// �޸� ����.
	operator delete(p2);
}






