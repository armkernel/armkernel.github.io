// 5_trivial1
#include <iostream>
using namespace std;

// Trivial : 하는일이 없다는 의미.
// Sample 클래스는 생성자가 trivial 할까요 ?

// 1. 가상함수가 없고
// 2. 객체형 멤버가 없거나, 객체형 멤버의 생성자가 trivial 하고
// 3. 기반 클래스가 없거나, 기반 클래스의 생성자가 trivial 하고
// 4. 사용자가 만든 생성자가 없다면

// "생성자는 trivial" 하다.


class Sample //: public Base
{	
	int n;
	//Data data;
public:
	Sample() : Base(), data() {}
	//virtual void foo() { cout << "foo" << endl; }
};

int main()
{
	Sample* p = static_cast<Sample*>(operator new(sizeof(Sample)));

	// 생성자 호출
	new(p) Sample;

	p->foo();
}

