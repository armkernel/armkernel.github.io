#include <iostream>
#include <type_traits>
using namespace std;

class Sample 
{
public:
	Sample(int n) {}
	//virtual void foo() { cout << "foo" << endl; }
	//void goo() {}

	//Sample()  {} // 사용자가 만든 아무일도 하지 않은 생성자
				// 아무일도 하지 않지만 컴파일러는 알수 없다.
				// trivial constructor가 아니다.

	Sample() = default; // 컴파일러에게 디폴트 생성자를 만들어 달라는 의미.
};



int main()
{
	cout << is_trivially_default_constructible_v<Sample> << endl;
}

