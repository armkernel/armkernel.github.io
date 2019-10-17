#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Data {};

class Test
{
	Data data;
public:
	// C++11 �������� �Ʒ� �Ѱ��� �˴ϴ�.
	void SetData(const Data& d) { data = d; }

	// C++11 ���Ŀ��� �Ʒ�ó�� �Ѱ� �� �߰��ϸ� �����ϴ�.
	void SetData(Data&& d)      { data = move(d); }

	// STL���� �̹� ��� Ŭ������ ��ó�� �Ǿ� �ֽ��ϴ�.
};

int main()
{
	vector<string> v;
	string s1 = "hello";

	v.push_back(s1);
	cout << s1 << endl; // ��� ������ ������.. "hello"

	v.push_back(move(s1));

	cout << s1 << endl; // ��� ������ ������.. ""
}