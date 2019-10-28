#include <iostream>

// raw 포인터의 문제점
int main()
{
  int* p1 = new int;
  int* p2 = p1;

  // 1. 메모리 누수 문제
  // memory 할당했는데 직접 쓰지 않는 문제

  // 2. dangling pointer
  delete p1;
  if ( p2 != 0 ) // 이미 삭제를 했는데.. p2가 자동으로 0으로 바뀌지는 않음
    *p2 = 10; // 삭제된 메모리 접근 

  // 3. double delete
  delete p2; // debug 모드 같은 것에는 죽을 수 있다.
}
