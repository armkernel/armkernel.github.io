// 4_move3.cpp
//
#include <iostream>
using namespace std;


class Buffer
{
  int* resource;
  int size;
public:
  Buffer(int sz) : size(sz) { resource = new int[sz]; }
  ~Buffer() { delete[] resource; }

  Buffer(const Buffer& b) : size (b.size)
  {
    cout << "copy 생성자" << endl;
    resource = new int[size];
    memcpy(resource, b.resource, sizeof(int)*size);
  }

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

  Buffer ret = foo(); // !! 

  Buffer b1(1024);
  Buffer b2 = b1; 

  // 더이상 b2가 필요 없다면 move가 호출되게 하는 것이 좋다.
  // rvalue로 데이터 속성을 변경
  // 더이상 필요없을 때, 이렇게 적으면 됨
  Buffer b3 = static_cast<Buffer&&>(b2); // 나 더이상 b2 안씀.

  Buffer b4 = std::move(b3);

  const Buffer cb(1024); // 상수

  Buffer b5 = cb; // copy
  //Buffer b6 = static_cast<Buffer&&>(cb);
  // Buffer b7 = static_cast<const Buffer&&> (cb); //ok.. 복사 생성자로 감.
  Buffer b8 = move(cb); //ok.. copy

  // 결론. const 객체는 move 될 수 없다.
}

