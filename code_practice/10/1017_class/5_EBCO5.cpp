// 5_EBCO1.cpp

// EBCO

#include <iostream>
#include <type_traits>
#include <tuple>
using namespace std;

class Empty{};

int main()
{
  tuple<Empty, int> t;

  cout << sizeof(t) << endl;
}


