// 6_함수객체2
#include <iostream>
#include <bitset>
using namespace std;

// 함수 객체의 장점 1. "상태" 를 가지는 함수

class URandom
{
	// 멤버 데이타를 통해 상태를 표현할수 있다.
	bitset<10> bs;
public:
	URandom() {	bs.set(); } // 모든 bit를 1로

	void reset() { bs.set(); }

	int operator()()
	{
		if (bs.none()) // 모두 0
			return -1;

		int k = -1;
		while (!bs.test(k = rand() % 10));
		bs.reset(k);
		return k;
	}
};
int main()
{
	URandom random;

	for (int i = 0; i < 10; i++)
		cout << random() << endl;
}





