// 7_람다표현식5

#include <iostream>
#include <type_traits>

using namespace std;

int main()
{
  auto f = [](int& a) -> int& { return a; };

  int n = 0;
  f(n);

  if ( is_lvalue_reference_v<decltype( f(n) )> )
      cout << "참조 반환" << endl;
  else
    cout << "값 반환" << endl;
}
