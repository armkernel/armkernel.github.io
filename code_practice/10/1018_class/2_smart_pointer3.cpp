#include <iostream>

using namespace std;

template<typename T>
class Ptr
{
  T* obj;
public:
  Ptr(T* p = 0) : obj(p) {}
  Ptr() { delete obj; }
  T* operator->() { return obj; }
  T& operator*() { return *obj; }
};



// Car 객체만 포인터를 사용하는 게 아니다.
// 범용적으로 만들어야함.
int main()
{
  Ptr<int> p1 = new int;

  *p1 = 10;
  cout << *p1 << endl;

  Ptr<int> p2 = p1; // 복사 생성자
  // 얕은 복사의 문제점.
  // 깊은 복사 -> 포인터의 원리.. => 같은 곳을 가리켜야하는데 다른 곳을 가리킴
  // 참조계수. 죽을 때, 카운트를 빼야함 
}
