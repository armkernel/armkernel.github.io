#include <iostream>
#include <algorithm>
#include <functional> 
using namespace std;

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	sort(x, x + 10); // ������ ���� ����

	// ����å ���� 1. �Ϲ� �Լ� ��� - �� ��å�� ġȯ �ȵ�. ������.
	// sort(x, x + 10, cmp1);

	// 2. �Լ� ��ü ���
	//greater<int> f;
	//sort(x, x + 10, f);
	
	// ��ü() : () ������ ȣ��
	// Ÿ��() : �ӽð�ü ����

	//sort( x, x + 10, greater<int>() ); // �ӽð�ü ���


	// 3. C++11 ���ʹ� ���� ǥ������ �����ϴ�.

	// [] : lambda introducer.   ���� ǥ������ ���۵��� �˸��� ��
	sort(x, x + 10, [](int a, int b) { return a < b;  } );


	// �� �ڵ带 ���� �����Ϸ��� �Ʒ� �ڵ带 �����մϴ�.
	class ClosureType
	{
	public:
		inline bool operator()(int a, int b) const
		{
			return a < b;
		}
	};
	sort(x, x + 10, ClosureType() );






	
	for (int n : x)
		cout << n << endl;
}





