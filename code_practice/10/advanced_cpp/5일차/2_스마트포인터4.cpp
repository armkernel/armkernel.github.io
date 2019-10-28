// 2_스마트포인터2
#include <iostream>
using namespace std;


template<typename T>
class Ptr
{
	T* obj;
	int* ref; // 참조계수를 관리할 포인터
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

	// 참조계수 관리를 위한 복사 생성자
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

	Ptr<int> p2 = p1;  // 복사 생성자.. 얕은복사 문제..

}