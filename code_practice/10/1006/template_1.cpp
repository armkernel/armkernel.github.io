/*
 * 템플릿 부분 특수화 주의사항
 * */

#include <iostream>

using namespace std;

template <typename T>
class stack { public: stack() {cout << typeid(T).name() << endl; } };


template <typename T>
class stack<T*> { public: stack() {cout << typeid(T).name() << endl; } };

int main()
{
  stack<int> s;
  stack<int*> s1;
}
