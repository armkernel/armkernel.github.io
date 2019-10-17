// 6_move_���ǻ���1
#include <iostream>
#include <string>
using namespace std;

// STL �� pair �� ������ Ŭ������ ����� ���ô�.
template<typename T, typename U> struct PAIR
{
	T first;
	U second;
	PAIR() = default;

	// ���� 2�� ¥�� ������ ���� first, second �ʱ�ȭ �غ�����
	PAIR( const T& a,  const U& b) : first(a), second(b) {}

	PAIR(T&& a, U&& b) : first(move(a)), second(move(b)) {}

	// C++11 ���� : ������(�Լ� ����)�� const T& �� �ַ� ���

	// C++11 ���� - move������ ���� 2���� �����ڸ� ���弼��
	// 1. const T&
	// 2. rvalue reference ���� - move�� ����!

};
int main()
{
	PAIR<int, int> p1(3, 4);
	string s1 = "hello";
	string s2 = "world";
	PAIR<string, string> p2(s1, s2);

	PAIR<string, string> p3(move(s1), move(s2));

	cout << s1 << endl; // 

	string s1 = "hello";
	string&& s2 = move(s1); // static_cast<string&&>(s1)
	string s3 = move(s2);
}




