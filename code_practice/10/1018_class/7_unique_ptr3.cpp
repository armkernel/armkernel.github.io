#include <iostream>

using namespace std;


// 자원해지 및 삭제 하는 함수 객체
template<typename T> struct xdefault_delete
{
  void operator()(T* p) const
  {
    static_assert(sizeof(T) > 0, "incomplete type!!");
    // void* delete하면 소멸자 부를 수 없다.
    delete p;
  }
};

template<typename T, typename D = xdefault_delete<T> >
class xunique_ptr
{
  T* obj;
public:
  explicit xunique_ptr(T* p = 0) : obj(p) {}
  ~xunique_ptr() 
  { 
    D d; // 어셈에서 치환
    d(obj); // 함수 객체 이므로 함수 처럼 사용
  }
  T* operator->() { return obj; }
  T& operator*() { return *obj; }

  xunique_ptr(const xunique_ptr&) = delete;
  xunique_ptr& operator=(const xunique_ptr&) = delete;
};

struct Freer
{
  // 구현부가 안에 있으면, inline.
  constexpr void operator()(void* p)
  {
    cout << "free" << endl;
    free(p);
  }
};

int main()
{
  // unique ptr은 가벼운게 목적
  // template 인자로 받음
  // 성능향상 목표
  // 유연성이 떨어짐.
  xunique_ptr<int> p1(new int);
  xunique_ptr<int,Freer> p2( (int*)malloc(100), foo );


  // 생성자 인자로 변경
  // 같은 타입 => 삭제자를 변경해도 상관없음
  // 묶어서 처리하기 좋음
  shared_ptr<int> sp1(new int);
  shared_ptr<int> sp2((int*)malloc(100), free);

}
