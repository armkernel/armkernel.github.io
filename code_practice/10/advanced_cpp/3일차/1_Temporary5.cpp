#include <iostream>
using namespace std;

class Test
{
public:
	//void foo() { cout << "&" << endl; } // 모든 객체가 호출가능

	void foo() & { cout << "&" << endl; } // 이름 있는 객체만 
										// 사용가능
	void foo() && { cout << "&&" << endl; } // temporary 만
									// 사용가능
};
int main()
{
	Test t;
	t.foo();
	Test().foo();

	((Test*)0)->foo(); // &
}

