// 3_move1
#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void foo(T a)
{
	// type traits 기술의 종류
	// 1. 타입 질의
	bool b1 = is_pointer<T>::value; // C++11
	bool b2 = is_pointer_v<T>;		// c++14

	// 2. 변형된 타입 얻기
	typename remove_pointer<T>::type n1; // C++11
	remove_pointer_t<T> n2;			// C++11
}


int main()
{

}
