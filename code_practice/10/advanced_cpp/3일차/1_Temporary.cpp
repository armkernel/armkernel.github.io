// 1_Temporary  
// github.com/webkit 
// webkit/source/wtf/wtf/scope.h ���� ������

#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) 
	{
		cout << "Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	
	void set(int a, int b) { x = a; y = b; }
};

// �ٽ� 1. temporary �� ����� ���.
//      2. temporary �� ����.

int main()
{
	//Point p(1, 1); // named object, ���� ������ �Ѿ �޸𸮿� ����
				   // ���� : ��ü�� ������ ���� ��

	//Point(1, 1); // unnamed object, temporary  (object)
				 // ���� : ������ ��(;)
				 // ���� ���忡���� ��밡��.

	Point(1, 1), cout << "X" << endl;

	cout << "----------" << endl;
}

