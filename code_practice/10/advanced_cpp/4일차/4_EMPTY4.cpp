#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	//vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	list<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = v.begin();
	++p; // ���� �ڵ� - ��� �ݺ��ڴ� ++�� �����ϴ�

	//p = p + 5;  // ���� ���� �ڵ� - �������� �ݺ��ڸ� ����
				// list �ݺ��ڴ� + ����ȵ�.

	advance(p, 5); // p�� �������� �̸� : p = p +5
					//    �ƴϸ� ++p �� 5��

	cout << *p << endl; 
}