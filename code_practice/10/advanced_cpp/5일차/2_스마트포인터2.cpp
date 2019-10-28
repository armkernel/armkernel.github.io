// 2_����Ʈ������2
#include <iostream>
using namespace std;

class Car
{
public:
	void Go() { cout << "Car Go" << endl; }
	~Car()    { cout << "~Car" << endl; }
};
// �Ʒ� �ڵ尡 �ٽ��Դϴ�.
// ���� : ������ ��ü�� �ٸ� Ÿ���� ������ ��Ȱ�� �ϴ� ��
// ���� : -> �� * �� ������ �ؼ� ������ ó�� ���̰� �Ѵ�.

// ���� : raw pointer �� �ƴ� ��ü�̴�.
//        ����/����/����/�Ҹ��� ������ �߰��� �۾��� �Ҽ� �ִ�.
//        ��ǥ�� Ȱ���� �Ҹ��ڿ��� �ڵ� ���� ���.
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}

	~Ptr() { delete obj; }
	Car* operator->() { return obj; }
	Car& operator*() { return *obj; }  // �ٽ�.. �ݵ�� ���� �����ؾ��մϴ�.
};

int main()
{
	Ptr p = new Car; // Ptr p( new Car )

	p->Go(); // (p.operator->())Go() ��� ���������
			 // (p.operator->())->Go() ó�� �ؼ��� �ݴϴ�.
	(*p).Go();// p.operator*()
}