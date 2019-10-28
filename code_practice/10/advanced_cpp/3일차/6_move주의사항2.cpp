#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Data {};

class Test
{
	Data data;
public:
	// C++11 이전에는 아래 한개면 됩니다.
	void SetData(const Data& d) { data = d; }

	// C++11 이후에는 아래처럼 한개 더 추가하면 좋습니다.
	void SetData(Data&& d)      { data = move(d); }

	// STL에는 이미 모든 클래스가 위처럼 되어 있습니다.
};

int main()
{
	vector<string> v;
	string s1 = "hello";

	v.push_back(s1);
	cout << s1 << endl; // 결과 예측해 보세요.. "hello"

	v.push_back(move(s1));

	cout << s1 << endl; // 결과 예측해 보세요.. ""
}