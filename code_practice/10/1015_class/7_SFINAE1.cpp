// 7_SFINAE - 215 page

#include <iostream>
using namespace std;

//template<typename T> 
// void foo(T a) { cout << "T" << endl; }
// void foo(int a) { cout << "int" << endl; }
//void foo(double a) { cout << "double" << endl; }
//void foo(char a) { cout << "char" << endl; }
//void foo(short a) { cout << "short" << endl; }
void foo(...) { cout << "..." << endl; }


int main()
{
  foo(10); // 어떤 것이 호출 될 것 인가?
           // 1. int
           // 2. T => template 으로 int버전 함수
           // 3. error. 모호하다
           // 4. ... 마지막.
           // 함수 오버로딩 revolution.
}
