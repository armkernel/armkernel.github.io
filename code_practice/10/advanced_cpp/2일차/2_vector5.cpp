#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1(10);
	vector<bool> v2(10);

	auto a1 = v1[0];
	auto a2 = v2[0];

	cout << typeid(a1).name() << endl; // int
	cout << typeid(a2).name() << endl; // ?

	// �ٽ�	1.
	// modern effective-c++ : vector<bool> �� ��ȯ�ϴ� ���� bool �� 
	//				�ƴϴ�.! auto ���� ����!!

	// �ٽ� 2. C++11 �� range -for ���� auto& �� �ϸ� ������ ���ü� �ִ�.
	//			�����̳ʰ� temporary(rvalue)�� ��ȯ�ϴ� ��찡 �ִ�.
	//          auto&& ( forwarding reference) �� ����.
	//for (auto& a : v1) // OK
	//for (auto& a : v2) // ERROR
	for (auto&& a : v2) // OK
		cout << a << endl;
}


