#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct People
{
	string name;
	People(string n) : name(n) {}
	~People() { cout << name << " ÆÄ±«" << endl; }

	weak_ptr<People> bestFriend;
};

int main()
{
	//shared_ptr<People> sp = make_shared<People>("kim");

	shared_ptr<People> sp(new People("kim"));

	weak_ptr<People> wp = sp;

	//

}






