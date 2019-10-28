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

	// C++11 이전에는 복사 생성자만 있었다.
	// 이름 있는 객체와 임시 객체 모두에 대해서 동일한 알고리즘 사용

	// C++11 이후 : 임시객체일때 복사하는	방법
	//		        이름 있는 객체 일때 복사하는 방법을
	//              분리해서 최적화 하자.

	Buffer(const Buffer& b) : size(b.size)
	{
		cout << "copy 생성자" << endl;
		resource = new int[size];
		memcpy(resource, b.resource, sizeof(int)*size);
	}
	// 인자로 임시객체가 올때는 메모리를 통째로 복사할 필요없다.
	// 주소만 복사 해오면 된다.
	Buffer( Buffer&& b) : size(b.size)
	{
		cout << "move 생성자" << endl;
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





