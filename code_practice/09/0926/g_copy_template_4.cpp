#include <iostream>

using namespace std;

template<typename T>
class Complex
{
  T im;
  T rm;

// 어떤게 올지 모름
public:
  Complex(const T& a = T{}, const T& b = T{}) : im(a), rm(b)
  {}
};

int main()
{
  Complex<int> c1(1,1);
  Complex<int> c2 = c1;

}
