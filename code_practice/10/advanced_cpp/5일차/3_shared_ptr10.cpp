// 3_shared_ptr10
#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main()
{
	int* p1 = new int;

	// �Ʒ� �ڵ�� ���� �ڵ� �ϱ�� ?
	shared_ptr<int> sp1(p1); // ������ü ����
	shared_ptr<int> sp2(p1); // �̼���, �� �ٸ� ������ü ����!!

	// �ٽ� : �ڿ��� ȹ�����Ŀ�,, �ڿ��� �����͸� �ڿ� ������ü�� ����
	//		����!!

	// �ڿ��� ȹ���� �ڿ� ���� ��ü�� ����� ���� ���ÿ� �ؾ� �Ѵ�
	shared_ptr<int> sp3(new int); // �̷��� �϶�°�
								// ����, make_shared ��  ������

	// RAII : Resource Acquision Is Initialization
}



