// 4_�������1
#include <iostream>
using namespace std;

// 71 page. CRTP ���
// CRTP : Curiously Recurring Template Pattern
//	      ��� Ŭ���� ���鶧 �̷��� ������� �Ļ� Ŭ���� �̸��� 
//			����Ҽ� �ְ� �ϴ� ����!!


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
	// ���� �Ҹ��ڴ� ������尡 �ִ�. �Ҹ��ڸ� �������� ��������
	// �ذ�����.
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
	p->deref();		// deref(p)
}


