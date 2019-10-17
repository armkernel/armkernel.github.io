// 6_함수객체2
#include <iostream>
using namespace std;

// 0 ~ 9 사이의 난수를 구하고 싶다.
// 단, 중복되지 않게 하고 싶다. - 기록해 놓기 위해 전역변수가 필요 하다.

// 함수는 동작이 있지만 상태가 없다.!!
int random()
{
	return rand() % 10;
}

int main()
{
	for (int i = 0; i < 10; i++)
		cout << random() << endl;
}





