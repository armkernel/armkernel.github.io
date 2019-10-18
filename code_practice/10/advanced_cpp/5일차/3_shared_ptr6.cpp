#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct People
{
	string name;
	People(string n) : name(n) {}
	~People() { cout << name << " �ı�" << endl; }

	//shared_ptr<People> bestFriend;  // ��������� �����Ѵ�.
	//People* bestFriend; 

	weak_ptr<People> bestFriend; // ��������� �������� �ʴ�
								// ����Ʈ ������. 
								// ��ü �ı� ���� ���� ����
};

int main()
{
	shared_ptr<People> sp1 = make_shared<People>("kim");
	{
		shared_ptr<People> sp2 = make_shared<People>("lee");

		sp1->bestFriend = sp2;
		sp2->bestFriend = sp1;
	}

	if (sp1->bestFriend.expired() )
	{
		cout << "��ü �ı���" << endl;
	}
}






