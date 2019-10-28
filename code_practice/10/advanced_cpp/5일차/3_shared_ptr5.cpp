#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct People
{
	string name;
	People(string n) : name(n) {}
	~People() { cout << name << " 파괴" << endl; }

	//shared_ptr<People> bestFriend;  // 참조계수가 증가한다.

	People* bestFriend; // 참조계수가 증가하지 않는다.
						// 객체가 파괴 되었는지 알수 없다.
						// Dangling Pointer 의 위험이 있다.
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






