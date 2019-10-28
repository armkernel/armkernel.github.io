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
		cout << "copy 생성자" << endl;
		resource = new int[size];
		memcpy(resource, b.resource, sizeof(int)*size);
	}
	
	Buffer(Buffer&& b) : size(b.size)
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
	Buffer ret = foo();  // move

	Buffer b1(1024);
	Buffer b2 = b1;	// copy

	// 더이상 b2가 필요 없다면 move가 호출되게 하는 것이 좋다.
	Buffer b3 = static_cast<Buffer&&>(b2); // b2 를 rvalue로 변경

	Buffer b4 = st::move(b3); // move 안에서 위처럼 캐스팅하고 있습니다.

	
	const Buffer cb(1024);

	Buffer b5 = cb; // copy
	//Buffer b6 = static_cast<Buffer&&>(cb); // error
	Buffer b7 = static_cast<const Buffer&&>(cb); // ok. copy

	Buffer b8 = move(cb);  // 1. error. 2. move  3.copy
							// 답은 copy

	// 결론 : const 객체는 move 될수 없습니다!!
}





