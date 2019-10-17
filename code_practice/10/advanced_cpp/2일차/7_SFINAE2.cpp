// 7_SFINAE - 215page
#include <iostream>
using namespace std;

//void foo(int a)    { cout << "int"    << endl; }


// 1. foo(10) => 템플릿 버전을 사용하기로 결정

// 2. T::type 을 int::type 으로 치환하니. 잘못된 표현식 등장
//    컴파일에러가 아니가 후보군에서 제외 된다.

// 3. 다른 버전의 foo 가 있으면 사용가능. 

// "치환실패는 에러가 아니다" 

// "Substitution Failure Is Not An Error" => SFINAE


template<typename T>
typename T::type foo(T a)  { cout << "T" << endl; return 0; }
// int::type

void foo(...) { cout << "..." << endl; }

int main()
{
	foo(10); 
}

