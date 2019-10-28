#include <iostream>

using namespace std;

template <typename T> void printN (const T& c) { cout << T::N << endl; }

template <typename T, typename U>
struct couple
{
  T v1;
  U v2;

  static constexpr int N = 2; // enum { N = 2 };
};

int main()
{
  couple<int, char> c2;

  couple<int, couple<int, double>> c3;
  couple<int, couple<couple<int,double>, double>> c4;

  printN(c2);
  printN(c3);
  printN(c4);
}
