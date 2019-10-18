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
	//People* bestFriend; 

	weak_ptr<People> bestFriend; // 참조계수가 증가하지 않는
								// 스마트 포인터. 
								// 객체 파괴 여부 조사 가능
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
		cout << "객체 파괴됨" << endl;
	}
}






