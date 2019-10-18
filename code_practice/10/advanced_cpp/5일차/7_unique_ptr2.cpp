// 7_unique_ptr
#include <iostream>
using namespace std;

template<typename T>
class xunique_ptr
{
	T* obj;
public:
	explicit xunique_ptr(T* p = 0) : obj(p) {}
	~xunique_ptr() { delete obj; }
	T* operator->() { return obj; }
	T& operator*() { return *obj; }

	// ����� ������ �����Ѵ�.
	xunique_ptr(const xunique_ptr&) = delete;
	xunique_ptr& operator=(const xunique_ptr&) = delete;
};

int main()
{
	//xunique_ptr<int> p1 = new int; // error
	xunique_ptr<int> p1(new int); // error

}