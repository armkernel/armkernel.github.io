#include <iostream>

using namespace std;

int print(int a)
{
  cout << a << ", ";
  return 0;
}

template<typename ... Types> void foo(Types ... args)
{
  // foo 안에서 args안에 있는 모든 요소를 print를 이용해서 출력해보자.
  // print(args); // error. 풀지 않으면 에러
  // print(args...); // print(1,2,3); error.
  //확장은 되지만 인자가 하나 밖에 없음 에러
  //
  // print(args)...; // 이렇게는 문법상 가능 => error.
  // 전역적으로 사용 불가능. 그래서 에러 발생함
  // print(1), print(2), print(3);
  //  ... 위치에 주의해라.

  // 아무곳이나 할 수 없다.
  //
  // print(args)...; <- 전역적인 공간에서는
  // pack expansion이 안된다.
  // 표준에서.. 막고 있음
  
  /* pack을 확장하는 것은
   * 1. 배열 초기화 list 초기화에서 가능
   *  2. 함수를 호출 하는 구문안에서 가능
  */
  //

  int x[] = { 0, (print(args),0)... }; // 배열의 초기화에서는 가능하니까. 여기에 넣고 하면 된다.


  // int x[] = { print(args)... };
  // { print(1), print(2), print(3) };

  // 위의 문제.. 
  // 아무것도 보내지 않으면..?
  //
  // 배열을 초기화 할때, 아무것도 없으면 에러
  // int x[] ={};
  // => G++은 해줄 수도 있다.. 컴파일러마다 달라.
  // 0,를 적어주면 에러안남.
  // int x[] = { 0, print(args)... };
  //
  // 만약 함수의 반환값이 "void" 라면.. 배열에 받을 수 없으니 => error.
  // int x[] = { 0, void? } <= error.

  // { 0, (print(1),0), (print(2),0), };
  //  전체 수식의 리턴값은 0을 쓰겠다. c에서 사용하는 방법.
  //  dummy를 써야한다.
  //  표현을 쓰기 위해서..
  //  int x[] = { 0, (print(args),0)... }; // c에서 괄호 안에서 함수가 있고 뒤에 인자가 있다면, 2번째인자를 사용함.
  //
  initializer_list<int> e = { (print(args),0)... }; // 일반 배열은 컴파일러마다 에러날 수 있지만, initializer list는 에러없이 잘 컴파일 된다. 0이라는 더미를 안써도 empty초기화가 가능하기 때문에 에러 없이 사용가능

  // fold expression <- c++17 부터 이런걸 깔끔하게 정리해준다.
}

int main()
{
  foo();
  // foo(1,2,3); // args : 1,2,3
}
