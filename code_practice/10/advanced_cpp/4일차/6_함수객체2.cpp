// 6_�Լ���ü2
#include <iostream>
using namespace std;

// 0 ~ 9 ������ ������ ���ϰ� �ʹ�.
// ��, �ߺ����� �ʰ� �ϰ� �ʹ�. - ����� ���� ���� ���������� �ʿ� �ϴ�.

// �Լ��� ������ ������ ���°� ����.!!
int random()
{
	return rand() % 10;
}

int main()
{
	for (int i = 0; i < 10; i++)
		cout << random() << endl;
}





