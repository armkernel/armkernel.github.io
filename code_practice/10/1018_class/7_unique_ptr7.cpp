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


template<typename T> struct xdefault_delete<T[]>
{
  void operator()(T* p) const
  {
    static_assert(sizeof(T) > 0, "incomplete type!!");
    // void* delete하면 소멸자 부를 수 없다.
    cout << " delete[] "<< endl;
    delete[] p;
  }
};

template<typename T, typename D = xdefault_delete<T> >
class xunique_ptr
{
  PAIR<D, T*> item;
public:
  // Default 값이 없으면, 추론 자체가 불가능함. 
  template<typename DX = D>
  explicit xunique_ptr(T* p = 0, DX&& d = DX()) 
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
  
  xunique_ptr(xunique_ptr&& other) 
    : item(move(other.item)) // PAIR 자체의 move 호출
  {
    other.item.getValue2() = nullptr; // pointer는 0으로.
    // compile가 move를 만들어주는데 부모에서..
    // nullptr로 초기화 안해줬을 거니까 우리가 해준다.
  }
  xunique_ptr& operator=(xunique_ptr&& other)
  {
    if (this == &other) return *this;

    item = move(other.item);
    
    other.item.getValue2() = nullptr;
    return *this;
  }
};

// 부분 특수화의 매칭 
// default 값은 T로 됨 => int[] 
template<typename T, typename D >
class xunique_ptr<T[], D>
{
  PAIR<D, T*> item;
public:
  // Default 값이 없으면, 추론 자체가 불가능함. 
  template<typename DX = D>
  explicit xunique_ptr(T* p = 0, DX&& d = DX()) 
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
  
  xunique_ptr(xunique_ptr&& other) 
    : item(move(other.item)) // PAIR 자체의 move 호출
  {
    other.item.getValue2() = nullptr; // pointer는 0으로.
    // compile가 move를 만들어주는데 부모에서..
    // nullptr로 초기화 안해줬을 거니까 우리가 해준다.
  }
  xunique_ptr& operator=(xunique_ptr&& other)
  {
    if (this == &other) return *this;

    item = move(other.item);
    
    other.item.getValue2() = nullptr;
    return *this;
  }
};


int main()
{
  xunique_ptr<int> p1(new int);
  // 아래와 같이 하는게 제일 좋다.
  xunique_ptr<int[]> p2(new int[10]); // T :int []이다.
  // 컴파일 에러

}
