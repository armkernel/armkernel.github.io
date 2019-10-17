// 6_�Լ���ü2
#include <iostream>
#include <bitset>
using namespace std;

// �Լ� ��ü�� ���� 1. "����" �� ������ �Լ�

class URandom
{
	// ��� ����Ÿ�� ���� ���¸� ǥ���Ҽ� �ִ�.
	bitset<10> bs;
public:
	URandom() {	bs.set(); } // ��� bit�� 1��

	void reset() { bs.set(); }

	int operator()()
	{
		if (bs.none()) // ��� 0
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





