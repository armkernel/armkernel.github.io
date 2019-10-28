// 4_참조계수1
#include <iostream>
using namespace std;

class RefCounted
{
	mutable int m_count = 0;
public:
	void ref()   const { ++m_count; }

	void deref() const  // void deref( RefCounted* this)
	{ 
		if (--m_count == 0) delete this;
	}
	// 기반 클래스 타입의 포인터로 삭제 할때 파생 클래스의 소멸자가
	// 호출되게 하려면 가상 소멸자를 사용해야 한다.
protected:
	virtual ~RefCounted() {  }
};

// Truck 도 참조계수로 관리하고 싶다.
class Truck : public RefCounted
{
public:
	~Truck() { cout << "Truck 파괴" << endl; }
};
int main()
{
	Truck* p = new Truck;
	p->ref();
	p->deref();		// deref(p)
}


