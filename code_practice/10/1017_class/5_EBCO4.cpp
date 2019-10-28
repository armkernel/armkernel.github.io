// 5_EBCO1.cpp

// EBCO

#include <iostream>
#include <type_traits>
using namespace std;

class Empty {};

// 아래 코드가 boost 라이브러리 안에 있는 compressed pair 라이브러리
// 입니다. www.boost.org

template<typename T, typename U, bool b = is_empty_v<T> > 
struct PAIR; 
//{  }
// primary template을 만들 떄, block에 내용이 없으면, 선언만 하면 됨.
// 조건에 따라 나눈다.
//
// Empty 는 첫번째 넣어라 구현한 사람이 룰을 정한 것.

// PAIR<int, int, false> p;
// 조건에 따라 PAIR를 부분특수화 한다.
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

int main()
{
  PAIR<Empty, int> p2;
  cout << sizeof(p2) << endl;
  
  PAIR<int, int> p3; // ?
  cout << sizeof(p3) << endl;
}


