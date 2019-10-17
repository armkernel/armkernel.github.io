// 5_EBCO1.cpp

// EBCO

#include <iostream>
using namespace std;

class Empty {};

class PAIR
{
  Empty e;
  int n;
};

// Memory layout같은데.. empty를 base class로 사용하면 최적화 될 수 있다.
//
// EBCO = Empty Base Class optimization
//      Empty 클래스를 기반 클래스로 사용하면 크기가 0으로 계산된다.
class PAIR2 : public Empty
{
  int n;
};

int main()
{
  cout << sizeof(Empty) << endl;
  cout << sizeof(PAIR)  << endl; // 구조체 , 클래스 패딩에 의해 8
  cout << sizeof(PAIR2)  << endl; // 구조체 , 클래스 패딩에 의해 8

}

