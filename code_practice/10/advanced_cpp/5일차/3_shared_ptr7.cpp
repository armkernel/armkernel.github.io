#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct People
{
	string name;
	People(string n) : name(n) {}
	~People() { cout << name << " �ı�" << endl; }

	weak_ptr<People> bestFriend; 
};

int main()
{
	shared_ptr<People> sp1;
	weak_ptr<People> wp1;


	shared_ptr<People> sp2 = make_shared<People>("kim");
	
	//sp1 = sp2;  // ���� ��� 2
	wp1 = sp2;    // ���� ��� ���� ����
	cout << sp2.use_count() << endl;

	//---------------------------------
	shared_ptr<People> sp3 = make_shared<People>("lee");

	shared_ptr<People> sp4 = sp3;
	weak_ptr<People>   wp4 = sp3;

	// �Ʒ� �ڵ���� �׻� �����ұ�� ?
	string s1 = sp4->name; // sp4�� ����ִ� ���� ��ü�� �ı��ɼ� ����.
							// dangling pointer�� ���ü� ����.

	string s2 = wp4->name;	// wp4�� ��� �ִٰ� �ص� ��ü��
							// ��� �ִٴ� ������ ����!!
							// �׷��� ��ü�� �����Ҽ� ����.
							// -> �� * �����ڰ� ������ �Ǿ� ���� �ʴ�

	// wp�� ����Ű�� ��ü�� �����Ϸ���
	// ��������� �ø��� �����ؾ� �Ѵ�.
	// ��������� �ø��� ����� "shared_ptr" �� ������ �Ѵ�.

	shared_ptr<People> sp5 = wp4.lock();

	if (sp5)
	{
		// ���� �����ϰ� ��ü�� ���� ����
		string s3 = sp5->name;
	}
}






