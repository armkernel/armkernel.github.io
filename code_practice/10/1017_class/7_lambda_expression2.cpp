#include <iostream>
#include <type_traits>

using namespace std;

// 함수를 인자로 받고 싶다.
// 값보다는 참조가 좋다.
// 임시 객체를 쓰게 되면, 전달 받을 수 없다.
// func => 상수 객체가 된다.
//

class Test
{
public:
  void operator()(int a, int b) & { cout << "&" << endl; }
  void operator()(int a, int b) && { cout << "&&" << endl; }
};


template<typename T> void foo(T&& func)
{
  //func(1,2); // func가 const 이므로 () 연산자가 const 멤버이어야한다.

  std::forward<T>(func)(1,2);
}

int main()
{
  foo([](int a, int b) { return a+b; });

}
