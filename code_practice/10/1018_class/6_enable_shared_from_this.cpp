#include <iostream>
#include <memory>
#include <string>

using namespace std;

template<typename T> class xenable_shared_from_this
{
public:
  weak_prt<T> wp;
  shared_pty<T> shared_from_this() { return wp.lock(); }
};

class Point : public xenable_shared_from_this<Point>
{
  int x, y;
public:
  void foo()
  {
    shared_prt<Point> p = shared_from_this();
  }
}

class RefManager {};
template<typename T> class shared_ptr
{
  T* obj;
  RefManager* manager;
public:
  shared_ptr(T* p)
  {
    obj = p;
    manager = new manager; // 초기화함
    // 관리 객체가 만들어짐.


    if( is_base_of_v<xeanble_shared_from_this<T>,T> ) // 기반 클래스 테스트 함수
      obj->wp = *this;
  }
}
