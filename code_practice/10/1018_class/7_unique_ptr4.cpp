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
  D dx; // 삭제자 보관
public:
  explicit xunique_ptr(T* p = 0, const D& d = D()) 
    : obj(p), dx(d) {}
  ~xunique_ptr() 
  { 
    //D d; // 어셈에서 치환
    dx(obj); // 함수 객체 이므로 함수 처럼 사용
  }
  T* operator->() { return obj; }
  T& operator*() { return *obj; }

  xunique_ptr(const xunique_ptr&) = delete;
  xunique_ptr& operator=(const xunique_ptr&) = delete;
};


int main()
{
  // lambda.. => 객체.. 데이터 타입이 들어가야해.
  // 람다.. 임시객체.. 
  // 아래 코드는 C++20 부터 가능합니다.

  auto del = [](int* p) { free(p); };

  xunique_ptr<int, decltype(del) > p1((int*)malloc(100), del);
  // 이거 안된다.
  // 왜>?
  // 시험 문제 => default 생성자가 ㅇ벗다.
/*
  auto f1 = [](int a, int b) { return a + b; };
           // class xxx{}; xxx();
  decltype(f1) f2; // error.. xxx 안에는 디폴트 생성자 없다.

  decltype(f1) f2(f1); // 복사 생성자.
  */
}
