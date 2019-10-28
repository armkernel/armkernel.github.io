#include <iostream>

using namespace std;

// 알고리즘 함수 제작과 move
//
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




template<typename T> void Swap(T& a, T& b)
{
  // 복사 생성자에 의한 Swap - 느리다.
  // T tmp = a;
  // b = a;
  // a = tmp;
  // 메모리 그림.
  //
  // move 생성자에 의한 swap 빠르다.
  T tmp = move(a);
  b = move(a); // move 대입 연산자.
  a = move(tmp);
}

int main()
{
  Buffer b1(1024);
  Buffer b2(1024);
  Swap(b1,b2);
  // move를 안만들었다면 ? 에러가 날까? 
  // const가 있으면.. 거기루 간다.
  // 없으면.. 못가나? 갈수있나? 갈 수 있다.
  // move가 없다고 해도 copy 로간다.
  
  string s1 = "hello";
  string s2 = "world";

  Swap(s1, s2);

  int n = 10;
  int n1 = static_cast<int&&>(n); // 아무 문제 없다.
  int n2 = move(n); // ok.. n는 동적할당된 자원이 없다.
                    // 빨라지는 것은 아니다.
                    // 오버헤드 없다.
}
