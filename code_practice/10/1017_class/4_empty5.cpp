// 4_EMPTY - 73page
//
#include <iostream>
#include <vector>
#include <list>

using namespace std;
/*
// 5개의 반복자 종류를 타입화 합니다. - empty class 활용
// 5개의 개념을 타입화 했으므로 함수 오버로딩 등에 활용될 수 있다.
struct input_iterator_tag {}
struct output_iterator_tag {}
struct forward_iterator_tag : input_iterator_tag {}
struct bidirectional_iterator_tag : forward_iterator_tag {}
struct random_access_iterator_tag : bidirectional_iterator_tag {}

// 이제 다양한 반복자를 만드는 사람은 반드시 iterator_category를 
// 제공하도록 약속합니다.


// 흉내
template<typename T> class vector_iterator
{
public:
  typedef random_access_iterator_tag iterator_category;
  // 벡터의 반복자의 타입은 randomw이라는 것
}

template<typename T> class list_iterator
{
public:
  typedef bidirectional_iterator_tag iterator_category;
}

c++ 표준에 다 있다.
*/

template<typename T> 
void xadvance_imp(T& p, int n, random_access_iterator_tag)
{
  cout << " random 일 때" << endl;
  p = p + n;
}

// true_type, false_type 이랑 비슷

// 기반 클래스라서 이것만 만들어두면, 다 여기로 귀속됨
// "Tag Dispatching" => 꼬리표 분배. 
// is_pointer<T>() => true_type, false_type 함수 호출과 유사한 개념
template<typename T> 
void xadvance_imp(T& p, int n, input_iterator_tag)
{
  cout << " input 일 때" << endl;
  while(n--) ++p;
}

template<typename T> void xadvance(T& p, int n)
{
  //p = p + n; // 그냥 다섯칸 이동하지.. 
             // vector는 되는데.. list가 안됨.
             // ++ 하자니.. 성능 저하가 일어남.
             // 구별해서 반복자 타입에 맞게 사용하자.
             // 그럼.. 구별할 수 있는 타입이 있어야함.
             //
  xadvance_imp(p, n, typename T::iterator_category());
  // template에 의존적으로 typedef를 꺼냄. 
  // 타입을 전달하기 위해서는 임시객체를 만들어야해
}

int main()
{
  list<int> v = { 1,2,3,4,5,6,7,8,9,10 };

  auto p = v.begin();
  xadvance(p,5);                  
  cout << *p << endl;

}




