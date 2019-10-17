// 4_EMPTY - 73page
//
#include <iostream>
#include <vector>
#include <list>

using namespace std;


template<typename T> 
void xadvance(T& p, int n)
{
  if constexpr (is_same_v<decay_t<typename T::iterator_category>,random_access_iterator_tag>)
  {
    p = p + n;
  }
  else 
  {
    cout << " input 일 때" << endl;
    while(n--) ++p;  
  }
}

// 함수 3개.. => 2개로 줄여보자

int main()
{
  list<int> v = { 1,2,3,4,5,6,7,8,9,10 };

  auto p = v.begin();
  xadvance(p,5);                  
  cout << *p << endl;

}




