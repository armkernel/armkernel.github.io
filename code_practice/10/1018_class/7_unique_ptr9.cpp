#include <iostream>
#include <memory>

using namespace std;

int main()
{
  unique_ptr<int> up1(new int);
  unique_ptr<int[]> up2(new int[10]); // C++14 먼저 됨

  // 에러를 모두 골라 보세요.
  //
  *up1 = 10;  // ok
  // up1[0] = 10; // error

  // *up2 = 10;   // error
  up2[0] = 10; // ok

  // 다음 중 에러를 모두 골라보세요.
  shared_ptr<int> sp(new int);
  unique_ptr<int> up(new int);

  shared_ptr<int> p1 = up; //error 
  shared_ptr<int> p2 = move(up); // ok unique_ptr이 shared_ptr로 move만 가능하다.
  unique_ptr<int> p3 = sp;      // error
  unique_ptr<int> p4 = move(sp); //error 

}

// * 대신 스마트 포인터를 사용하고 싶습니다.
// 아래 함수의 반환타입을 뭘로 할까요? shared? unique?
//
//int* AllocBuffer(int size)
// shared_ptr<int> AllocBuffer(int size) // unique 안됨.
unique_ptr<int> AllocBuffer(int size) // 사용자가 결정할 수 있다.
  // 함수가 반환하려면 .. unique_ptr로 반환해라
{
  //return static_cast<int*>( malloc(size) );
  return static_cast<int*>(new int);
}


int[3] a; // a의 타입은 int[3];
int[4] a;

int[] : unkown size array type.. 이라는 이름을 가진 타입.
        // incomplete type이므로 이 타입의 객체는 만들 수 없음.
        // template에서만 사용

void foo(int[] arg) // 주의: unkown size arraY 아니다.
                    // int* 입니다.
                    //

// C++ 표준 스마트 포인터 : shared_ptr, weak_ptr, unique_ptr
//
int main()
{
  int n = 0;
  int* p = &n;  // p를 스마트 포인터로 변경할 수 있을까요?
  shared_ptr<int> p (&n); 
}

// shared_ptr<int> ret1 = AllocBuffer(100);
// unique_ptr<int> ret2 = AllocBuffer(100);
//

// cafe.naver.com/cppmaster 에 cppmaster.h 받아 놓으라
