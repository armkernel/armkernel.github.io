#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> 
typename enable_if< is_integral<T>::value, void>::type
foo(T a)
{
	cout << "T" << endl;
}

void foo(...) { cout << "..." << endl; }

int main()
{
	// ���� �϶��� T, ������ �ƴϸ� ... �ǰ� �غ�����.
	foo(10);  // T
	foo(3.4); // ...
	foo(3.4f);// ...
}





