// 6_enable_shared_from_this
#include <iostream>
#include <memory>
#include <type_traits>
using namespace std;

template<typename T> class xenable_shared_from_this
{
public:
	weak_ptr<T> wp;
	shared_ptr<T> shared_from_this() { return wp.lock(); }
};

class Point : public xenable_shared_from_this<Point>
{
	int x, y;
public:
	void foo()
	{
		shared_ptr<Point> p = shared_from_this();
	}
};
/*
class RefManager {};
template<typename T> class shared_ptr
{
	T* obj;
	RefManager* manager;
public:
	shared_ptr(T* p)
	{
		obj = p;
		manager = new manager; // 초기화하고..

		if (is_base_of_v<xenable_shared_from_this<T>, T>)
			obj->wp = *this;
	}
};
*/
int main()
{
	shared_ptr<Point> sp(new Point);

	enable_shared_from_this<Point> a;
}





