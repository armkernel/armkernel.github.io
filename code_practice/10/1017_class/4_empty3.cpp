// 4_EMPTY - 73page
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


int main()
{
  vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

  // find 알고리즘의 1,2번째 인자는 반복자 입니다.
  // 최소 요구 조건을 말해보세요 => 입력반복자
  auto p = find(v.begin(), v.end(), 3);

  reverse(v.begin(), v.end()); // 최소 양방향.

  sort(v.begin(), v.end()); // 퀵소트 알고리즘 - 뺄셈이 되야함.
                            // 임의접근 반복자
                            //
  // ----------------------------------
  forward_list<int> s1 = { 1,2,3 };
  reverse(s1.begin(), s1.end()); //

  list<int> s2 = { 1,2,3 };
  sort(s2.begin(), s2.end());

  // 에러가 많이 나와서 어떤 에러인지 찾지 못함.
  // 코드를 보고 모른다. 
  // STL 쓰면안돼.
  s2.sort(); // 이 친구 자체 sort list내 

  vector<int> v2 = { 1,2,3,4 }; // vector는 멤버함수가 제일 적다.
  
}




