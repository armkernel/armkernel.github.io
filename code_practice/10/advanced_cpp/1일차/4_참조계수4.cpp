// 4_�������1
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
	// ��� Ŭ���� Ÿ���� �����ͷ� ���� �Ҷ� �Ļ� Ŭ������ �Ҹ��ڰ�
	// ȣ��ǰ� �Ϸ��� ���� �Ҹ��ڸ� ����ؾ� �Ѵ�.
protected:
	virtual ~RefCounted() {  }
};

// Truck �� ��������� �����ϰ� �ʹ�.
class Truck : public RefCounted
{
public:
	~Truck() { cout << "Truck �ı�" << endl; }
};
int main()
{
	Truck* p = new Truck;
	p->ref();
	p->deref();		// deref(p)
}


