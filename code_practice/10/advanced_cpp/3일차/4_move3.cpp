// 4_move3.cpp
#include <iostream>
using namespace std;

class Buffer
{
	int* resource;
	int  size;
public:
	Buffer(int sz) : size(sz) { resource = new int[sz]; }

	~Buffer() { delete[] resource; }

	// C++11 �������� ���� �����ڸ� �־���.
	// �̸� �ִ� ��ü�� �ӽ� ��ü ��ο� ���ؼ� ������ �˰��� ���

	// C++11 ���� : �ӽð�ü�϶� �����ϴ�	���
	//		        �̸� �ִ� ��ü �϶� �����ϴ� �����
	//              �и��ؼ� ����ȭ ����.

	Buffer(const Buffer& b) : size(b.size)
	{
		cout << "copy ������" << endl;
		resource = new int[size];
		memcpy(resource, b.resource, sizeof(int)*size);
	}
	// ���ڷ� �ӽð�ü�� �ö��� �޸𸮸� ��°�� ������ �ʿ����.
	// �ּҸ� ���� �ؿ��� �ȴ�.
	Buffer( Buffer&& b) : size(b.size)
	{
		cout << "move ������" << endl;
		resource = b.resource;
		b.resource = 0;
	}
};
Buffer foo()
{
	Buffer buf(1024);
	return buf;
}
int main()
{
	Buffer ret = foo();  // !!

	Buffer b1(1024);
	Buffer b2 = b1;
}





