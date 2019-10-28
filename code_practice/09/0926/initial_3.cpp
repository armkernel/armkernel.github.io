#include <iostream>
#include <initializer_list>
using namespace std;

class foo
{
public:
  foo(int a, int b) { cout << "int , int" << endl; }
  foo(initializer_list<int>) { cout << "initializer_list" << endl; }
  explicit foo(const foo&) {}
};

int main()
{
  initializer_list<int> e = { 1, 2, 3, 4, 5 };
  foo(1,2);
  //foo(1);
  foo{1,2};
  foo({1,2});
}
