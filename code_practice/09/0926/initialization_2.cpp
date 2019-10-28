#include <iostream>

using namespace std;

int main()
{
  int a = 0;
  int a1(1);
  int a2{1};
  
  int a3 = 1;
  int a4 = {1};

  cout << a << " , " << a1 << " " << a2 << " " << a3 << " " << a4 << " " << endl;
}
