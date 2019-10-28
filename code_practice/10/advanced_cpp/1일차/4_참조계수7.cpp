#include <iostream>
#include <atomic>   // C++11 
using namespace std;

// www.google.com 에서 "github android source" 검색후

// 1번째 링크
// "platform_system_core" 찾으세요 (2page에 있을겁니다.)

// libutils/include/utils/LightRefBase.h 열어 보세요


template<typename T> class RefCounted
{
	mutable atomic<int> m_count = 0;
public:
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
	~Truck() { cout << "Truck 파괴" << endl; }
};
int main()
{
	Truck* p = new Truck;
	p->ref();
	p->deref();
}

