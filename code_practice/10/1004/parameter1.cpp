#include <iostream>

using namespace std;

template<typename T, int N> struct Array
{
  T buff[N];
};


int main()
{
  int n = 10;
  constexpr int n1 = 10;

  Array<int, 10> ar; // ok
  Array<int, n> ar1; // error
  Array<int, n1> ar2; // ok
}
