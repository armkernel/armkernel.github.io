#include <iostream>
#include <atomic>   // C++11 
using namespace std;

// www.google.com ���� "github android source" �˻���

// 1��° ��ũ
// "platform_system_core" ã������ (2page�� �����̴ϴ�.)

// libutils/include/utils/LightRefBase.h ���� ������


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
	~Truck() { cout << "Truck �ı�" << endl; }
};
int main()
{
	Truck* p = new Truck;
	p->ref();
	p->deref();
}

