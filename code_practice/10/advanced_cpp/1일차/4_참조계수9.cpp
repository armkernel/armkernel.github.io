#include <iostream>
#include <atomic>   
using namespace std;

#define WTF_MAKE_NONCOPYABLE(classname)				\
	classname(const classname&) = delete;			\
	classname& operator=(const classname&) = delete;

// 코드 메모리를 줄이기 위해
// template 클래스 안에서 T를 사용하지 않은 모든 멤버는
// 기반 클래스로 옮기자(기반 클래스는 template이 아니어야 한다.)

// Thin Template  - 237 Page 기술

// github.com/webkit    접속해 보세요

// source/wtf/wtf/RefCounted.h  찾아 보세요



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
	~Truck() { cout << "Truck 파괴" << endl; }
};


int main()
{
	Truck* p1 = new Truck; 	p1->ref();
	Truck* p2 = p1;         p2->ref();
	p1->deref();
	p2->deref();
}

