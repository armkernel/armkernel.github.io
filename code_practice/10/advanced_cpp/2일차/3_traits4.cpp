#include <iostream>
using namespace std;

// �Ʒ� ����� �̹� ���� traits �� �ֽ��ϴ�
#include <type_traits>

template<typename T> void foo()
{
	bool b1 = std::is_array<T>::value;// C++11 ����.
	bool b1 = std::is_array_v<T>;     // C++14 ����

	//std::is_
}
int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}


