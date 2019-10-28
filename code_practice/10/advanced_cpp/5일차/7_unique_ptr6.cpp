// 7_unique_ptr
#include <iostream>
using namespace std;


template<typename T, typename U, bool b = is_empty_v<T> >
struct PAIR;

template<typename T, typename U> struct PAIR<T, U, false>
{
	T first;
	U second;
	PAIR() = default;

	template<typename A, typename B>
	PAIR(A&& a, B&& b) : first(std::forward<A>(a)),
		second(std::forward<B>(b)) {}

	T& getValue1() { return first; }
	U& getValue2() { return second; }
};

template<typename T, typename U> struct PAIR<T, U, true> : public T
{
	U second;

	PAIR() = default;

	template<typename A, typename B>
	PAIR(A&& a, B&& b) : T(std::forward<A>(a)),
		second(std::forward<B>(b)) {}

	T& getValue1() { return *this; }
	U& getValue2() { return second; }
};



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
	//T* obj;
	//D dx;		// ������ ����

	PAIR<D, T*> item;
public:

	template<typename DX = D>
	explicit xunique_ptr(T* p = 0, DX&& d = DX())
		: item(std::forward<DX>(d), p) {}

	~xunique_ptr()
	{
		item.getValue1()(item.getValue2());
	}

	T* operator->() { return item.getValue2(); }
	T& operator*() { return *item.getValue2(); }

	xunique_ptr(const xunique_ptr&) = delete;
	xunique_ptr& operator=(const xunique_ptr&) = delete;
	
	// move �� �����ؾ� �Ѵ�.
	xunique_ptr(xunique_ptr&& other)
			: item(move(other.item)) // PAIR ��ü�� move ȣ��
	{
		other.item.getValue2() = nullptr; // ���� ��ü�� �����ʹ� 0����
	}
	xunique_ptr& operator=(xunique_ptr&& other)
	{
		if (this == &other) return *this;

		item = move(other.item);
		other.item.getValue2() = nullptr;
		return *this;

	}
};





int main()
{
	xunique_ptr<int> p1(new int);
	//xunique_ptr<int> p2 = p1;		// error
	xunique_ptr<int> p3 = move(p1); // �Ǿ� �Ѵ�.

}