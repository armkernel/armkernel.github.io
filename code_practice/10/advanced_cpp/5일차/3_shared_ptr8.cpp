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
	shared_ptr<People> sp1 = make_shared<People>("kim");
	{
		shared_ptr<People> sp2 = make_shared<People>("lee");

		sp1->bestFriend = sp2;
		sp2->bestFriend = sp1;
	}

	if (sp1->bestFriend.expired())
	{
		cout << "��ü �ı���" << endl;
	}
	else
	{
		// ��� �ִ� ���..
		//cout << sp1->bestFriend->name << endl; // error.
									// weak ���� -> �� ����

		shared_ptr<People> sp = sp1->bestFriend.lock();

		if (sp)
		{
			cout << sp->name << endl;
		}

	}
}






