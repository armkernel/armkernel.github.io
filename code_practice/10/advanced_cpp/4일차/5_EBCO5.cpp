#include <iostream>
#include <type_traits>
#include <tuple>
using namespace std;

class Empty {};

int main()
{
	tuple<Empty, int> t;

	cout << sizeof(t) << endl; // �� ���ñ�� ?
				// g++ : 4
				// vc++ : 8
}



