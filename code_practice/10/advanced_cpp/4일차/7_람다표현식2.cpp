#include <iostream>
#include <type_traits>
using namespace std;

class Test
{
public:
	void operator()(int a, int b) &	{  cout << "&" << endl;	}
	void operator()(int a, int b) && { cout << "&&" << endl; }
};

// 함수를 인자로 받고 싶습니다.
//template<typename T> void foo(const T& func)
template<typename T> void foo(T&& func) // Test&& func = Test()
{
	//func(1, 2); // func 가 const 이면 () 연산자가 const 멤버이어야한다.
	//func(1, 2);

	std::forward<T>(func)(1, 2);
}
int main()
{
	Test t; 	foo(t);
	foo(Test());


//	foo([](int a, int b) {return a + b; });
}