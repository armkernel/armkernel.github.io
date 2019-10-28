#include <iostream>
#include <tuple>

using namespace std;

template<typename ... Types> void foo(Types ... args)
{
  // pack expansion
  // 담을 수 있는 방법 중에 하나이지만,
  // 문제가 있다.
  // pack안에 들어있는 다른 타입 일 경우 배열에 다 담지 못한다.
  //int x[] = { args... };

  // tuple
  tuple<Types...> tp(args...);

  // tuple 요소 뺴오는 방법
  //  tuple의 문제점. get 또한 template이기 때문에 변수를 넣지 못함. 
  //  for문으로 출력할 수 없고 컴파일 상수를 사용해야한다.
  cout << get<0>(tp) << endl;
  cout << get<1>(tp) << endl;
  cout << get<2>(tp) << endl;



  // 다른 방법. 재귀호출과 유사한 호출식을 사용


}

// parameter pack에서 각 요소를 빼는 것을 알아보자.

int main()
{
  foo(1, 3.4, "AA"); // args : 1, 3.4, "AA"
}
