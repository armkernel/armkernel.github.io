// 6_int2type1.cpp - 115 page

// template 은 2번 컴파일 한다.
// 1. T와 관련 없는 부분의 오류를 조사 합니다
//    T와 관련 있는 코드는 조사하지 않습니다.

// 2. 실제 사용하면 T타입이 결정되고.. 실제 함수(클래스)의 코드가 생성.
//    생성된 함수를 다시 컴파일(오류조사) 합니다.

// "참고 : C++ template complete guide 2nd edition"

// 아래 함수 코드는 에러일까요 ?
template<typename T> void foo(T a)   // void foo(int a)
{
	*a = 10;
	goo(a);
	goo();
}

int main()
{
	//foo(10);
}