// 7_SFINAE - 215 page

#include <iostream>
using namespace std;

// 1. foo(10) => 템플릿 버전을 사용하기로 결정
//
// 2. T::type을 int::type으로 치환하니, 잘못된 표현식 등장.
//    컴파일 에러가 아니라 후보군에서 제외된다.
//
// 3. 다른 버전의 foo가 있으면, 사용가능.
//
// 4. 치환 실패는 에러가 아니다.
//
// 5. SFINAE => "Substitution Failure Is Not An Error"

// 만약 아무것도 없다면, 컴파일 에러나는데.. 에러의 메세지가 함수가 없다는 내용임. 이 함수가 잘못됐다는 내용이 아님.


template<typename T> 
typename T::type foo(T a) { cout << "T" << endl; return 0; }
// 함수의 반환값이 생기면 어떻게 될까? => 문제없다.
// 반환값을 template type으로 변경한다면?
// T가 int를 깨닫고 int::type이라는 잘못된 표현이라는걸 깨닫는다.
// 이럴 경우 가변인자를 쓸 것인가? => page 215
//
// SFINAE => Substitution Failure Is Not An Error


void foo(...) { cout << "..." << endl; }


int main()
{
  foo(10); // 어떤 것이 호출 될 것 인가?
  // 함수 호출 시 어떤 함수로 가야할지는 파라메타를 보고 결정
  // 
}
