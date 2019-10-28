// 7_unique_ptr
#include <iostream>
using namespace std;

// �ڿ��� �����ϴ� �Լ� ��ü
template<typename T> struct xdefault_delete
{
	void operator()(T* p) const
	{
		static_assert(sizeof(T) > 0, "incomplete type!!");
		delete p;
	}
};



template<typename T, typename D = xdefault_delete<T> >
class xunique_ptr
{
	T* obj;
	D dx;		// ������ ����
public:
	explicit xunique_ptr(T* p = 0, const D& d = D() ) 
		: obj(p), dx(d) {}



	~xunique_ptr()
	{
		dx(obj);
	}




	T* operator->() { return obj; }
	T& operator*() { return *obj; }

	xunique_ptr(const xunique_ptr&) = delete;
	xunique_ptr& operator=(const xunique_ptr&) = delete;
};


int main()
{
	auto del = [](int* p) { free(p); };

	xunique_ptr<int, decltype(del) > p1((int*)malloc(100), del);




	
	/*
	// �Ʒ� �ڵ�� C++20 ���� �����մϴ�.
	xunique_ptr<int, decltype( [](int* p) { free(p); } ) > p1((int*)malloc(100));
	auto f1 = [](int a, int b) { return a + b; };
			// class xxx{};  xxx();

	decltype(f1) f2; // error.. xxx �ȿ��� ����Ʈ �����ڰ� ����.
	decltype(f1) f2(f1); // ok.

	*/
}