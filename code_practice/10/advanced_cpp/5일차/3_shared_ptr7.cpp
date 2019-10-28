#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct People
{
	string name;
	People(string n) : name(n) {}
	~People() { cout << name << " 파괴" << endl; }

	weak_ptr<People> bestFriend; 
};

int main()
{
	shared_ptr<People> sp1;
	weak_ptr<People> wp1;


	shared_ptr<People> sp2 = make_shared<People>("kim");
	
	//sp1 = sp2;  // 참조 계수 2
	wp1 = sp2;    // 참조 계수 증가 안함
	cout << sp2.use_count() << endl;

	//---------------------------------
	shared_ptr<People> sp3 = make_shared<People>("lee");

	shared_ptr<People> sp4 = sp3;
	weak_ptr<People>   wp4 = sp3;

	// 아래 코드들은 항상 안전할까요 ?
	string s1 = sp4->name; // sp4가 살아있는 동안 객체는 파괴될수 없다.
							// dangling pointer가 나올수 없다.

	string s2 = wp4->name;	// wp4가 살아 있다고 해도 객체가
							// 살아 있다는 보장이 없다!!
							// 그래서 객체에 접근할수 없다.
							// -> 와 * 연산자가 재정의 되어 있지 않다

	// wp가 가리키는 객체에 접근하려면
	// 참조계수를 올리고 접근해야 한다.
	// 참조계수를 올리는 방법은 "shared_ptr" 을 만들어야 한다.

	shared_ptr<People> sp5 = wp4.lock();

	if (sp5)
	{
		// 이제 안전하게 객체에 접근 가능
		string s3 = sp5->name;
	}
}






