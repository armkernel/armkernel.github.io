#include <iostream>

using namespace std;


// 77 page 이야기..
// C++11 부터 enable_if는 표준
template<bool b, typename T> struct enable_if
{
  typedef T type;
};

// 부분특수화에는 default값 안쓰는게 맞음
// 고정된 값이 있다면, template앞에 내용 빼는 게맞음.
template<typename T> struct enable_if<false,T>
{
};

int main()
{
  enable_if<true, int>::type n1; // int
  enable_if<true, double>::type n2; // double
  enable_if<true>::type n3; // default 없으면, error -> 있으면 그 default로 감
                            // 만약 void가 있다면, void는 만들 수 없기 때문에 error.
  enable_if<false, int>::type n4; // error. ::type 멤버가 없다.
}
