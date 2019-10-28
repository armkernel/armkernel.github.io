#include <iostream>

using namespace std;

void goo (int n, double d, const char* s)
{
  cout << "goo : " << n << " " << d << " " << s << endl;
}

template<typename ... Types>
void foo(Types ... args)
{
  // agrs에는 파라메타가 여러개 들어있다.
  // 이런 것을 parameter pack 이라고 부른다.
  // 흔히 몇개가 있는지 알고 싶다면, C++11 부터 나오는 sizeof... 연산자를 이용하면 된다.
  
  // sizeof...에는 타입의 갯수와 args 갯수를 둘 다 구할 수 있다.
  cout << sizeof...(args) << endl;
  cout << sizeof...(Types) << endl;

//  goo( args ); // parameter pack을 함수 인자로 보낸다? 그건 에러..
  goo(args...); // pack expansion.
  // parameter를 pack으로 보내고 싶다면 "..."을 붙이면 된다. 흔히, pack expansion이라고 부른다.
  // 만약 하나씩 뽑아 쓰고 싶다면, (,)를 이용하면돼. goo( e1, e2, e3 )
  //  goo (1, 3.4, "AAA")
  //  함수 인자타입들을 같게 만들어 두면 거기로 보내짐.
}

int main()
{
//  foo();
//  foo(1);
  foo(1,3.4,"AAA");  // Types : int, double, const char* 가 들어있음.
                     // args : 1, 3.4, "AAA" 
  
}

/*
 * 1. Parameter Pack
 * 2. sizeof...(args) : parameter Pack에 있는 요소의 개수 출력할 때, 사용하는 키워드
 * 3. Pack Expansion
 * */
