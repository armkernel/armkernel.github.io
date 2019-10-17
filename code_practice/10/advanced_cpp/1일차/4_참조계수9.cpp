#include <iostream>
#include <atomic>   
using namespace std;

#define WTF_MAKE_NONCOPYABLE(classname)				\
	classname(const classname&) = delete;			\
	classname& operator=(const classname&) = delete;

// �ڵ� �޸𸮸� ���̱� ����
// template Ŭ���� �ȿ��� T�� ������� ���� ��� �����
// ��� Ŭ������ �ű���(��� Ŭ������ template�� �ƴϾ�� �Ѵ�.)

// Thin Template  - 237 Page ���

// github.com/webkit    ������ ������

// source/wtf/wtf/RefCounted.h  ã�� ������



class RefCountedBase
{
protected:
	mutable atomic<int> m_count = 0;
public:
	void ref()   const { m_count.fetch_add(1); }
};

template<typename T> class RefCounted : public RefCountedBase
{
	WTF_MAKE_NONCOPYABLE(RefCounted)


public:
	RefCounted() {}

	void deref() const
	{
		if (m_count.fetch_sub(1) == 1)
			delete static_cast<const T*>(this);
	}

protected:
	~RefCounted() {  }
};

class Car : public RefCounted< Car >
{

};

class Truck : public RefCounted< Truck >
{
public:
	Truck() {}
	~Truck() { cout << "Truck �ı�" << endl; }
};


int main()
{
	Truck* p1 = new Truck; 	p1->ref();
	Truck* p2 = p1;         p2->ref();
	p1->deref();
	p2->deref();
}

