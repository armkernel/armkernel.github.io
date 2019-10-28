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

	Buffer(const Buffer& b) : size(b.size)
	{
		cout << "copy ������" << endl;
		resource = new int[size];
		memcpy(resource, b.resource, sizeof(int)*size);
	}
	
	Buffer(Buffer&& b) : size(b.size)
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
	Buffer ret = foo();  // move

	Buffer b1(1024);
	Buffer b2 = b1;	// copy

	// ���̻� b2�� �ʿ� ���ٸ� move�� ȣ��ǰ� �ϴ� ���� ����.
	Buffer b3 = static_cast<Buffer&&>(b2); // b2 �� rvalue�� ����

	Buffer b4 = st::move(b3); // move �ȿ��� ��ó�� ĳ�����ϰ� �ֽ��ϴ�.

	
	const Buffer cb(1024);

	Buffer b5 = cb; // copy
	//Buffer b6 = static_cast<Buffer&&>(cb); // error
	Buffer b7 = static_cast<const Buffer&&>(cb); // ok. copy

	Buffer b8 = move(cb);  // 1. error. 2. move  3.copy
							// ���� copy

	// ��� : const ��ü�� move �ɼ� �����ϴ�!!
}





