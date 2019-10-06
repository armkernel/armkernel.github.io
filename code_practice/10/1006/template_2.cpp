/*
 * 템플릿 부분 특수화 주의사항2
 * */

#include <iostream>

using namespace std;

template <typename T, int N = 10>
struct stack
{
  stack() { cout << typeid(T).name() << endl << N  << endl; }
};

template <typename T, int N>
struct stack <T*,N>
{
  stack() { cout << typeid(T).name() << endl << N  << endl; }
};

int main()
{
  stack<int, 20> s1;
  stack<int*> s;
}
