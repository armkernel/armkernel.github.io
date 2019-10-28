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
	/*
	Buffer(Buffer&& b) : size(b.size)
	{
		cout << "move 생성자" << endl;
		resource = b.resource;
		b.resource = 0;
	}
	*/
};

// 알고리즘 함수 제작과 move
template<typename T> void Swap(T& a, T& b)
{
	// 복사 생성자에 의한 Swap - 느리다.
	//T tmp = a;
	//b = a;
	//a = tmp;

	// move 생성자에 의한 Swap - 빠르다.
	T tmp = move(a);
	b = move(a);
	a = move(tmp);
}
int main()
{
	Buffer b1(1024);
	Buffer b2(1024);
	Swap(b1, b2);

	string s1 = "hello";
	string s2 = "world";
	Swap(s1, s2);


	int n = 10;
	int n1 = static_cast<int&&>(n); // 아무 문제 없습니다.
	int n2 = move(n); //ok.. n 는 동적 할당된 자원이 없습니다.
					  // 빨라지는 것은 아닙니다.
					  // 오버헤드도 없습니다.
}

