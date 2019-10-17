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
			//delete static_cast<T*>(this); // error. 왜 에러일까요 ?

			//delete static_cast<T*>(const_cast<RefCounted*>(this));

			delete static_cast<const T*>(this);
	}

protected:
	~RefCounted() {  }
};

class Truck : public RefCounted< Truck >
{
public:
	~Truck() { cout << "Truck 파괴" << endl; }
};
int main()
{
	Truck* p = new Truck;
	p->ref();
	p->deref();		
}




// 5교시 까지의 코드는 cafe.naver.com/cppmaster에 있습니다.

// 필요 하신 분들은 받으시면 됩니다.