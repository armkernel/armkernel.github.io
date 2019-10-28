// 2_����Ʈ������2
#include <iostream>
using namespace std;


template<typename T>
class Ptr
{
	T* obj;
	int* ref; // ��������� ������ ������
public:
	Ptr(T* p = 0) : obj(p), ref(new int(1)) {}
	
	~Ptr() 
	{
		if (--(*ref) == 0)
		{
			delete obj;
			delete ref;
		}
	}

	T* operator->() { return obj; }
	T& operator*() { return *obj; }

	// ������� ������ ���� ���� ������
	Ptr(const Ptr& p) : obj(p.obj), ref(p.ref)
	{
		++(*ref);
	}

};


int main()
{
	Ptr<int> p1 = new int;
	*p1 = 10;
	cout << *p1 << endl;

	Ptr<int> p2 = p1;  // ���� ������.. �������� ����..

}