#include <iostream>
#include <type_traits>
using namespace std;

class Sample 
{
public:
	Sample(int n) {}
	//virtual void foo() { cout << "foo" << endl; }
	//void goo() {}

	//Sample()  {} // ����ڰ� ���� �ƹ��ϵ� ���� ���� ������
				// �ƹ��ϵ� ���� ������ �����Ϸ��� �˼� ����.
				// trivial constructor�� �ƴϴ�.

	Sample() = default; // �����Ϸ����� ����Ʈ �����ڸ� ����� �޶�� �ǹ�.
};



int main()
{
	cout << is_trivially_default_constructible_v<Sample> << endl;
}

