#include <iostream>
using namespace std;

template<typename T> class RefCounted
{
	mutable int m_count = 0;
public:
	void ref()   const { ++m_count; }

	void deref() const  
	{
		if (--m_count == 0)
			//	delete (T*)this;
			//delete static_cast<T*>(this); // error. �� �����ϱ�� ?

			//delete static_cast<T*>(const_cast<RefCounted*>(this));

			delete static_cast<const T*>(this);
	}

protected:
	~RefCounted() {  }
};

class Truck : public RefCounted< Truck >
{
public:
	~Truck() { cout << "Truck �ı�" << endl; }
};
int main()
{
	Truck* p = new Truck;
	p->ref();
	p->deref();		
}




// 5���� ������ �ڵ�� cafe.naver.com/cppmaster�� �ֽ��ϴ�.

// �ʿ� �Ͻ� �е��� �����ø� �˴ϴ�.