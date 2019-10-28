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

	People* bestFriend; // ��������� �������� �ʴ´�.
						// ��ü�� �ı� �Ǿ����� �˼� ����.
						// Dangling Pointer �� ������ �ִ�.
};

int main()
{
	shared_ptr<People> sp1 = make_shared<People>("kim");
	{
		shared_ptr<People> sp2 = make_shared<People>("lee");

		sp1->bestFriend = sp2.get();
		sp2->bestFriend = sp1.get();
	}

	if (sp1->bestFriend != nullptr)
	{
		cout << sp1->bestFriend->name << endl; // ??
	}
}






