#include <iostream>
#include <memory>
#include <Windows.h>
using namespace std;

class Point
{
public:
	Point()  { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

void foo(void* p) { cout << "foo" << endl; free(p); }
int main()
{
	// ������ ����
	shared_ptr<int>  p1(new int);          // p1 �Ҹ��ڿ��� delete
	shared_ptr<void> p2(malloc(100), foo); // �Ҹ��ڿ��� foo ȣ��
	shared_ptr<void> p3(malloc(100), free);
	shared_ptr<void> p4(malloc(100), [](void* p) { free(p); } );

	// �迭 ������� �Ҵ�
	//shared_ptr<int> p5(new int[10]); // ����.. delete[] �� �ʿ�
	shared_ptr<int> p6(new int[10], [](int* p) {delete[] p; });

	// default_delete<int> : delete    �� �����ϴ� �Լ� ��ü
	// default_delete<int[]> : delete[]
	shared_ptr<int> p7(new int[10], default_delete<int[]>() );

	// ���������δ� C++17 ���� ���� ����
	shared_ptr<int[]> p8(new int[10] );

	shared_ptr<Point[]> p9(new Point[3]);

//	Point* pt = new Point[3]; // ������ 3�� ȣ��
//	delete pt; // �Ҹ��� �ѹ� ȣ��

	// 
	shared_ptr< FILE > sp1(fopen("a.txt", "wt"), fclose );

	HANDLE h = CreateEvent(0, 0, 0, 0);
	CloseHandle(h);

	//shared_ptr< remove_pointer<HANDLE>::type > sp2(CreateEvent(0, 0, 0, 0), CloseHandle);
}







