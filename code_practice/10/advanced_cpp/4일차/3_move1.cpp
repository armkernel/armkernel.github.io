// 3_move1
#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void foo(T a)
{
	// type traits ����� ����
	// 1. Ÿ�� ����
	bool b1 = is_pointer<T>::value; // C++11
	bool b2 = is_pointer_v<T>;		// c++14

	// 2. ������ Ÿ�� ���
	typename remove_pointer<T>::type n1; // C++11
	remove_pointer_t<T> n2;			// C++11
}


int main()
{

}
