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

struct Freer
{
	void operator()(void* p)
	{
		cout << "Free" << endl;
		free(p);
	}
};

template<typename T, typename D = xdefault_delete<T> >
class xunique_ptr
{
	T* obj;
public:
	explicit xunique_ptr(T* p = 0) : obj(p) {}
	
	~xunique_ptr()
	{
		D d;
		d(obj); // �Լ���ü�̹Ƿ� �Լ�ó�� ���
	}




	T* operator->() { return obj; }
	T& operator*() { return *obj; }

	xunique_ptr(const xunique_ptr&) = delete;
	xunique_ptr& operator=(const xunique_ptr&) = delete;
};
int main()
{
	// ������ ������ ���ø� ���ڷ�
	xunique_ptr<int> p1(new int);
	xunique_ptr<int, Freer> p2( (int*)malloc(100) );
	

	// ������ ���ڷ� ����
	shared_ptr<int> sp1(new int);
	shared_ptr<int> sp2((int*)malloc(100), free);

	
}