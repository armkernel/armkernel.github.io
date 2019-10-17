// 4_참조계수1
#include <iostream>
using namespace std;

// 71 page. CRTP 기술
// CRTP : Curiously Recurring Template Pattern
//	      기반 클래스 만들때 미래에 만들어질 파생 클래스 이름을 
//			사용할수 있게 하는 패턴!!


template<typename T> class RefCounted
{
	mutable int m_count = 0;
public:
	void ref()   const { ++m_count; }

	void deref() const  // void deref( RefCounted* this)
	{
		if (--m_count == 0) 
			delete (T*)this;
	}
	// 가상 소멸자는 오버헤드가 있다. 소멸자를 가상으로 하지말고
	// 해결하자.
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
	p->deref();		// deref(p)
}


