// 5_trivial1
#include <iostream>
using namespace std;

// Trivial : �ϴ����� ���ٴ� �ǹ�.
// Sample Ŭ������ �����ڰ� trivial �ұ�� ?

// 1. �����Լ��� ����
// 2. ��ü�� ����� ���ų�, ��ü�� ����� �����ڰ� trivial �ϰ�
// 3. ��� Ŭ������ ���ų�, ��� Ŭ������ �����ڰ� trivial �ϰ�
// 4. ����ڰ� ���� �����ڰ� ���ٸ�

// "�����ڴ� trivial" �ϴ�.


class Sample //: public Base
{	
	int n;
	//Data data;
public:
	Sample() : Base(), data() {}
	//virtual void foo() { cout << "foo" << endl; }
};

int main()
{
	Sample* p = static_cast<Sample*>(operator new(sizeof(Sample)));

	// ������ ȣ��
	new(p) Sample;

	p->foo();
}

