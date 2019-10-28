#include <iostream>

using namespace std;

class Empty {};

// 아래 코드가 boost 라이브러리 안에 있는 compressed pair 라이브러리
// 입니다. www.boost.org

template<typename T, typename U, bool b = is_empty_v<T> > 
struct PAIR; 
template<typename T, typename U> struct PAIR <T,U, false>
{
  T first;
  U second;

  PAIR() = default;

  template<typename A, typename B>
  PAIR(A&& a, B&& b) : first(std::forward<A>(a)), 
                       second(std::forward<B>(b))
  {
  }

  T& getValue1() { return first; }
  U& getValue2() { return second; }
};


template<typename T, typename U> struct PAIR<T,U, true> : public T
{
  U second;

  PAIR() = default;

  template<typename A, typename B>
  PAIR(A&& a, B&& b) : T(std::forward<A>(a)), 
                       second(std::forward<B>(b))
  {
  }

  T& getValue1() { return *this;  } // 상속 받으면 제일 위해 base class이기 때문에 *this를 쓰면 됨.
  U& getValue2() { return second; }
};



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
  // T* obj;
  // D dx; // 삭제자 보관
  PAIR<D, T*> item;
public:
  template<typename DX>
  explicit xunique_ptr(T* p = 0, DX&& d = D()) 
    : item(std::forward<DX>(d),p) {}

  ~xunique_ptr() 
  { 
    //D d; // 어셈에서 치환
    // dx(obj); // 함수 객체 이므로 함수 처럼 사용
    item.getValue1()( item.getValue2() );
  }
  T* operator->() { return item.getValue2(); }
  T& operator*() { return *item.getValue2(); }

  xunique_ptr(const xunique_ptr&) = delete;
  xunique_ptr& operator=(const xunique_ptr&) = delete;
};


int main()
{
  // lambda.. => 객체.. 데이터 타입이 들어가야해.
  // 람다.. 임시객체.. 
  // 아래 코드는 C++20 부터 가능합니다.

  auto del = [](int* p) { free(p); };

  // lambda는 괄호연산자 밖에 없고 멤버 데이터가 없으니까
  // Empty이다.!! 중요
  xunique_ptr<int, decltype(del) > p1((int*)malloc(100), del);

  cout << sizeof(p1) << endl;

}
