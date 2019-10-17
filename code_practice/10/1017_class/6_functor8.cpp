#include <iostream>
#include <algorithm>
#include <functional> // less<>, greater<> 여기에 있다.

using namespace std;

int main()
{
  int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

  sort(x, x + 10); // 무조건 오름 차순

  // 비교정책 변경1. 일반함수 사용 - 비교 정책이 치환 안됨. 느리다.
  // sort(x, x + 10, cmp1);
  //
  // 2. 함수 객체 사용
  // greater<int> f;
  // sort(x, x + 10, f);
  
  // 객체() -> 임시객체 만들어라
  // 데이터 타입() 를 붙이면 -> 객체 만들기 
  // sort(x, x+10, greater<int>()); //임시객체 사용


  // 3. C++11 부터는 람다 표현식이 좋습니다.
  sort(x, x + 10, [](int a, int b) { return a < b; });
  // 신기술..
  // 구현 코드를 보냄 => 람다 표현식

  // [] : lambda introducer : 람다가 시작됨을 알려준다.
  // 뒷 부분은 함수랑 똑같음.
  //
  
  // 위 코드를 보고 컴파일러는 아래의 코드를 생성한다.
  //
  // 람다 표현식을 아래와 같이 만듬.
  /*
  class ClouserType
  {
    public:
      inline bool operator()(int a, int b) const
      {
        return a < b;
      }
  };

  치환되기 때문에 코드가 길어지는 건 상관없다.

  sort(x, x+10, ClouserType()); // 컴파일러에 의해 이렇게 변형됨.
  */

  
  for (int n : x)
    cout << n << endl;


}
