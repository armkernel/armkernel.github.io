// 4_EMPTY - 73 page
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// STL �ݺ���

// �Է� �ݺ���     : =*p, ++   �̱� �н��� ����
// ��� �ݺ���     : *p=, ++   �̱� �н��� ����
// ������ �ݺ���   : =*p, ++,			=> �̱۸���Ʈ �ݺ���
// ����� �ݺ���   : =*p, ++, --		=> ������Ʈ �ݺ���
// �������� �ݺ��� : =*p, ++, --, +, -, []    => ���ӵ� �޸�

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// find �˰����� 1,2��° ���ڴ� �ݺ��� �Դϴ�.
	// �ּ� �䱸������ ���� ������ => �Է¹ݺ���
	auto p = find(v.begin(), v.end(), 3); 

	reverse(v.begin(), v.end()); // �����

	sort(v.begin(), v.end()); // �� ��Ʈ �˰��� - 
						// ���� ���� �ݺ���
	//---------------------------------
//	forward_list<int> s1 = { 1,2,3 }; // �̱۸���Ʈ
//	reverse(s1.begin(), s1.end()); // error

	list<int> s2 = { 1,2,3 };
	sort(s2.begin(), s2.end()); // ?

	s2.sort(); // ok.. ���� �ƴ� �ٸ� �˰���.

	//vector<int> v2 = { 1,2,3,4 };
	//v2.sort(); // �� ��� �Լ��� ������� ? ����

	sort()
}



