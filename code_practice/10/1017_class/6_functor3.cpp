// 6_함수 객체
// 함수 객체 (function object) : 함수 처럼()를 사용해서 호출가능한 객체
#include <iostream>
#include <bitset>
using namespace std;


// 함수 객체의 장점 1. "상태" 를 가지는 함수


class URandom
{
  // 멤버 데이터를 통해 상태를 표현할 수 있다.
  bitset<10> bs;
public:
  URandom() {bs.set();} //모든 bit를 1로

  void reset() {bs.set();}
  int operator()()
  {
    if (bs.none()) return -1; //모두 0
    int k = -1;
    while(!bs.test(k = rand()% 10));
    bs.reset(k);
    return k;
  }
};

int random1()
{
  return rand() % 10;
}

int main()
{
  URandom random;
  for (int i = 0; i < 10; i++) 
    cout << random() << endl;
}
