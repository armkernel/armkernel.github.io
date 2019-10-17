#include <iostream>
#include <algorithm>
#include <functional> // less<>, greater<> 여기에 있다.

using namespace std;

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

int main()
{
  int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

  // sort() 함수는 모든 인자가 템플릿입니다.
  // 1. 비교정책으로 일반 함수를 사용할 때
  sort(x, x+10, cmp1); // sort(int*, int*, bool(*)(int,int)); 인 함수 생성 
  sort(x, x+10, cmp2); // sort(int*, int*, bool(*)(int,int)); 인 함수 생성
  // 다르지만 같은 타입.. (함수의 포인터 모양이 비슷하다.)
  // 장점 : 비교정책을 교체해도 sort() 기계어 코드는 한개이다.
  //        코드 메모리 증가 안한다.
  // 단점 : 하나 밖에 없는 코드에서는 인라인 치환 불가능. 따라서, 계속적인
  //        콜을 함. "느리다."

  // 2. 비교정책으로 함수객체를 사용할때
  //
  // 단점 : 정책을 교체한 횟수 만큼 sort 기계어 코드 생성
  //        code memory overhead존재.
  //
  // 장점 : 정책이 inline 치환됨. 빠르다.
  
  less<int> f1;     // STL 안에 이 함수객체가 있습니다.
  greater<int> f2;

  sort(x, x+10, f1); // sort(int*, int*, ?) 인 함수 생성
  sort(x, x+10, f2); // sort(int*, int*, ?) 인 함수 생성

  // 마지막 인자로 함수를 보내준다면, 그 함수를 가지고 비교정책을 따짐.
  // 모든 요소 비교할 때 마다 부른다.
  //  이걸 inline 치환하면 성능 향상
}
