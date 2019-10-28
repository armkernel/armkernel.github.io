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
	/*
	Buffer(Buffer&& b) : size(b.size)
	{
		cout << "move ������" << endl;
		resource = b.resource;
		b.resource = 0;
	}
	*/
};

// �˰��� �Լ� ���۰� move
template<typename T> void Swap(T& a, T& b)
{
	// ���� �����ڿ� ���� Swap - ������.
	//T tmp = a;
	//b = a;
	//a = tmp;

	// move �����ڿ� ���� Swap - ������.
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
	int n1 = static_cast<int&&>(n); // �ƹ� ���� �����ϴ�.
	int n2 = move(n); //ok.. n �� ���� �Ҵ�� �ڿ��� �����ϴ�.
					  // �������� ���� �ƴմϴ�.
					  // ������嵵 �����ϴ�.
}

