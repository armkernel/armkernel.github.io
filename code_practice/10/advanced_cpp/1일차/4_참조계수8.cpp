#include <iostream>
#include <atomic>   
using namespace std;

// ���� ������ ���� ���ȴ�.
// ��ũ��ȭ �Ѵ�.
#define WTF_MAKE_NONCOPYABLE(classname)				\
	classname(const classname&) = delete;			\
	classname& operator=(const classname&) = delete;


template<typename T> class RefCounted
{
	WTF_MAKE_NONCOPYABLE(RefCounted)

	// �Լ� ���� �������� ���� �����ڿ� ���Կ����ڸ� ���� �Ѵ�.
	// ���� �����ڿ� ���Կ����ڸ� ����ϸ� ������ ����.
	//RefCounted(const RefCounted&) = delete;
	//RefCounted& operator=(const RefCounted&) = delete;

	mutable atomic<int> m_count = 0;
public:
	RefCounted() {}
	void ref()   const { m_count.fetch_add(1); }

	void deref() const
	{
		if (m_count.fetch_sub(1) == 1)
			delete static_cast<const T*>(this);
	}

protected:
	~RefCounted() {  }
};

class Truck : public RefCounted< Truck >
{
public:
	Truck() {}
	~Truck() { cout << "Truck �ı�" << endl; }

	Truck(const Truck& t) 
	{
		// �� ����� ����.. ��� Ŭ������ ���������� �����ϰų�
		// ��� Ŭ������ ���� �����ڸ� ȣ�������� ����.
		// �����Ϸ��� ����� �ִ� ������ ��� Ŭ���� ���������
		// ȣ��
	}
};


int main()
{
	Truck* p1 = new Truck; 	p1->ref();
	Truck* p2 = p1;         p2->ref();

	Truck* p3 = new Truck(*p1); // !!!!
	p3->ref();

	p1->deref();
	p2->deref();
}

