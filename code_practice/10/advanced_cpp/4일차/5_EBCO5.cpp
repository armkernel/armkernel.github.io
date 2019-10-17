#include <iostream>
#include <type_traits>
#include <tuple>
using namespace std;

class Empty {};

int main()
{
	tuple<Empty, int> t;

	cout << sizeof(t) << endl; // 얼마 나올까요 ?
				// g++ : 4
				// vc++ : 8
}



