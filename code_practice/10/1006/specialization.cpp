#include <iostream>

using namespace std;

template<typename T> class Stack
{
  T data;
public:
  void push(T a) { cout << " T " << endl; }
};


template<typename T> class Stack<T*>
{
  T data;
public:
  void push(T a) { cout << " T* " << endl; }
};


template<> class Stack<char*>
{
  char* data;
public:
  void push(char* a) { cout << " char* " << endl; }
};

int main()
{
  Stack<int> s1;
  Stack<int *> s2;
  Stack<char *> s3;

  s1.push(0);
  s2.push(0);
  s3.push(0);

}
