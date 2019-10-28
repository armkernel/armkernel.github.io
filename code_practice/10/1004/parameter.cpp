#include <iostream>

using namespace std;

template<typename T, int N> struct Array
{
  T buff[N];
};


int main()
{
  Array<int, 10> ar;
}

// template parmeter로 전달받을 수 있는 경우의 수
//  1. type
//  2. non-type (value)
//  3. template


