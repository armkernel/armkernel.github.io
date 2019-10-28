#include <iostream>
#include <functional> // bind

using namespace std;
using namespace std::placeholders; // _1 _2 _3 .. 을 사용하기 위해 


void foo(int a, int b, int c, int d)
{
  printf("%d %d %d %d\n", a, b, c ,d);
}

void goo(int) { cout << " goo "<< endl; }

int main()
{
  // 일반 함수 포인터 단점
  //  1. 함수만 담는다. 함수 객체를 담을 수 없다.
  //  2. 인자의 갯수가 다른 함수를 담을 수 없다.
  // void(*f)(int);

  // C++ : 함수 포인터 대신 function을 사용하자 - C++11
  function<void(int)> f; // 함수 타입. => void(*)(int) 이렇게 적으면 안돼
  // 이런 모양의 함수를 담겠다는 의미.
  f = &goo;

  f(10); // goo(10);

  f = bind(&foo,1,2,3,_1); // 함수를 호출하는게 아니라.. 만드는 것. 따라서 뒤에 괄호를 붙이면 안돼
  // 그냥 담으면 안되고.. 4개짜리를 1개로 변경
 
  f = [](int a) { cout << "lambda" << endl;};

  f(10);

  // C++ GUI 라이브러리 : nana (C++11/14 를 활용한 라이브러리)


}

