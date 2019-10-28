#include <iostream>
#include <type_traits>
using namespace std;

class Test
{
public:
	void operator()(int a, int b) &	{  cout << "&" << endl;	}
	void operator()(int a, int b) && { cout << "&&" << endl; }
};

// �Լ��� ���ڷ� �ް� �ͽ��ϴ�.
//template<typename T> void foo(const T& func)
template<typename T> void foo(T&& func) // Test&& func = Test()
{
	//func(1, 2); // func �� const �̸� () �����ڰ� const ����̾���Ѵ�.
	//func(1, 2);

	std::forward<T>(func)(1, 2);
}
int main()
{
	Test t; 	foo(t);
	foo(Test());


//	foo([](int a, int b) {return a + b; });
}