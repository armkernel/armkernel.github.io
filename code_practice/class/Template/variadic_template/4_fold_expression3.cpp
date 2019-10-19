#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

template <typename ... Types>
void foo(Types ... args)
{
  // ( args, ...); // 1, (2,3)
  // parameter pack 만 오는 것이 아니라. 패턴도 사용할 수 있다.
  //
  (v.push_back(args), ...);
  // v.push_back(1), (v.push_back(2), v.push_back(3));
  // c에서 (,) 연산자는 앞에 것 실행하고 뒤에것 실행하도록 하는 것.

  for ( auto u : v )
    cout << u << endl;
}

// C, c++ 에서 (,)도 이항 연산자이다.

int main()
{
  foo(1, 2, 3);
}


