// 4_move5
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	const string s1 = "hello";
	//string s2 = s1;

	string s2 = std::move(s1);

	cout << s1 << endl;


	vector<int> v1(10, 3);
	//vector<int> v2 = v1;		// ������.. �޸𸮸� ��°�� ����
	vector<int> v2 = std::move(v1);// ������. �����͸� ����

	cout << v1.size() << endl;
}


