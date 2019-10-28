#include <iostream>
#include <tuple>

using namespace std;

void foo() {} // 재귀 종료를 위해서..


template<typename T, typename ... Types> void foo(T value, Types ... args)
{
  // 재귀호출과 유사한 방식으로 가변인자를 빼오기
  // 모든 인자를 가변인자로 받으면 안되고 첫번째 인자 만큼은 독립된 타입을 받아야함.
  
  cout << value << endl;
 
  foo(args...); // foo(3.4 , "AA");
                // foo("AA");
                // foo(); <- 마지막
                //  이렇게 되면 인자가 하나가 있어야하는데.. 인자가 없으니 에러가 남.
                //  재귀 호출이라는 표현은 썼지만 사실은 재귀가 아니다.
                //  왜냐하면, 처음 부를 때는 인자 3개짜리.. 2개짜리.. 1개짜리.. 없는 것.. 이렇게 부른 것임. 즉, 함수를 여러개 만든 것임. 
                //  확인 해보고 싶으면, static 변수 넣고 확인 해보면 된다.
                //
   static int n = 0;

   cout << "n: " << n++ << endl;
   // 단점 : 이 방식의 호출은 함수가 굉장히 많아 진다.
   // 만약 함수 자체가 크다면, 이 방식은 비 효율 적,...
}

// 핵심
// 1. Pack Exapansion -> 배열 또는 tuple, initializer list를 이용해 담는다.
// 2. 재귀 호출과 유사한 호출식을 사용한다.
//  - 모든 인자를 가변인자로 하지말고, 1번째 인자는 변수로 고정해서 받도록 한다.

int main()
{
  foo(1, 3.4, "AA"); // value : 1 args : 3.4, "AA"
}
