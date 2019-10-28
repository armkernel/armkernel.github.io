// 4_move3.cpp
//
#include <iostream>
using namespace std;

// 1. 클래스 안에 포인터 변수가 있으면 얕은 복사 현상이 있다.
// 2. 반드시 복사 생성자를 사용자가 만들어야 한다.

class Buffer
{
  int* resource;
  int size;
public:
  Buffer(int sz) : size(sz) { resource = new int[sz]; }
  ~Buffer() { delete[] resource; }

  // lvalue, rvalue를 다 받음
  // C++11  이전에는 복사생성만 있었다.
  // 이름 있는 객체와 임시 객체 모두에 대해서 동일한 알고리즘 사용
  
  // C++11 이후 : 임시객체일때 복사하는 방법
  //             이름 있는 객체 일때 복사하는 방법을
  //             분리해서 최적화 하자.
  Buffer(const Buffer& b) : size (b.size)
  {
    cout << "copy 생성자" << endl;
    resource = new int[size];
    memcpy(resource, b.resource, sizeof(int)*size);
  }

  // 인자가 임시객체가 올때, 메모리를 통째로 복사할 필요 없다.
  // 주소만 복사해오면 된다.
  // const는 빼야한다. 왜? pointer를 0으로 바꿔야해
  // 임시 객체일떄는 밑에걸 사용함.
  // 성능향상 올라간다.
  Buffer(Buffer&& b) : size (b.size)
  {
    cout << "move 생성자" << endl;
    resource = b.resource;
    b.resource = 0;
  }
};

Buffer foo()
{
  Buffer buf(1024);
  return buf;
}

int main()
{
  Buffer b1(1024);
  //Buffer b2 = b1; 

  Buffer ret = foo(); // !! 
  // 임시 객체 
  // 반환값 으로 온 것은 객체가 옴 
  // 깊은 복사 하지말고 얕은 복사 하자. 
  // 얕은 복사하면 임시객체가 죽을 때.. 지우면 노답. 그래서 죽을 때 0번지를 넣어줌
  // 0번지를 delete하는 건 아무 문제가 없음.
  // 포인터 복사로 가자.

  // 임시 객체 일때만 포인터를 빼가야함.
}

