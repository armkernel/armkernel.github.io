// 5_explicit1

class Vector
{
public:
	// explicit  : ���� �ʱ�ȭ�� �����ϰ� ���� �ʱ�ȭ�� ����Ҽ� ����
	explicit Vector(int sz) {}
};
// call by value �� ���� ���� : copy initilization ���
void foo(Vector v) {}  // Vector v = 10

int main()
{
	Vector v1(10);  // ok. direct initialization
	Vector v2 = 10; // ok  copy initialization  ( = �� �ʱ�ȭ)	
					// explicit ��� error

	foo(10);	// explicit ��� error


	goo(new int, hoo() ); // error

	shared_ptr<int> sp = new int; // error
	shared_ptr<int> sp(new int); // ok.
}

void goo(shared_ptr<int> sp, int n) {}
