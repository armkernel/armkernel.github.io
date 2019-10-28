#include <iostream>

using namespace std;

template<bool b, typename T, typename F>
struct IfThenElse
{
  T type;
};


template<typename T, typename F>
struct IfThenElse<false, T, F>
{
  F type;
};


template<typename F>
struct IfThenElse<false, short, F>
{
  F type;
};

int main()
{
  IfThenElse<true, int, char> b1;
  IfThenElse<false, int, char> b2;

  IfThenElse<(33 <= 32), short, int> n2;

  cout << typeid(b1.type).name() << endl;
  cout << typeid(b2.type).name() << endl;
  cout << typeid(n2.type).name() << endl;

}
