// 1_�Ϻ�������
#include <iostream>
#include <vector>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b)  : x(a), y(b) { cout << "Point()" << endl; }
	
	Point(const Point& p): x(p.x), y(p.y)
	{ 
		cout << "Point(const Point&)" << endl; 
	}
	~Point() { cout << "~Point()" << endl; }
};
int main()
{
	vector<Point> v;

	// v �� 1,2 �� �ʱ�ȭ�� Point�� �ְ� �ͽ��ϴ�.
	// 1. Point ��ü ������ �ֱ� - 1���� ��ü�� ������.
	//Point p1(1, 2);
	//v.push_back(p1);

	// 2. ��� 2
	// 2���� ��ü, move �����ڷ� ����
	//Point p1(1, 2);
	//v.push_back(move(p1));

	// 3. ��� 3. �ӽð�ü ���
	// 2���� ��ü, move ������, �ӽð�ü �̹Ƿ� ������ �� �ı�
	//v.push_back(Point(1, 2));

	// ��� 4. ��ü�� �ܺο��� ������ ���� vector�� ���� �����
	//        �Ѵ�.
	//        ��, ��ü�� ���鶧 �ʿ��� ������ ���� ����
	//v.emplace_back(1, 2); // �� �Լ��� ����������
						  // new Point(1,2)

//	v.push_back({ 1,2 }); // �ӽð�ü�� �����ϴ� �ڵ�!
							// �Ʒ� ����!
//	const Point& p = { 1,1 }; // 

	cout << "--------" << endl;
}