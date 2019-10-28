#include <iostream>
#include <vector>
using namespace std;
/*
template<typename T> class vector
{
public:
	typedef unsigned int size_type; // ũ�⸦ �����ϴ� Ÿ��
	size_type size() const { return 10; }
};
*/

//void foo(vector<int>& v)
template<typename T> void foo(T& v)
{
	// ?�� �� �ְ��� ������ ���� Ÿ���ϱ�� ?
	//unsigned int n = v.size();
	//vector<int>::size_type n = v.size(); // �ְ��� �ڵ�.

	typename T::size_type n = v.size(); // �ְ��� �ڵ�.
}

// cppreference.com ���� vector �˻��� ������

int main()
{
	vector<int> v(10);
	foo(v);
}