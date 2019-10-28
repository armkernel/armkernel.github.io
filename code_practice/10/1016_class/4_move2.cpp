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

  Buffer(const Buffer& b) : size (b.size)
  {
    // 포인터를 복사하지 말고, 메모리 복사 - 깊은 복사
    resource = new int[size];
    memcpy(resource, b.resource, sizeof(int)*size);
  }
};

int main()
{
  Buffer b1(1024);
  Buffer b2 = b1; // 얕은 복사 일어남. -> runtime error
                  // 깊은 복사로 변환해야함.
}


