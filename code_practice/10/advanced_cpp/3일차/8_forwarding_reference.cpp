// 8_forwarding_reference - 아주 중요합니다. C++11 의 핵심 기술

// int&  : int 타입의 lvalue 만 받을수 있다.
// int&& : int 타입의 rvalue 만 받을수 있다.
// T&    : 임의의 타입의 lvalue 만 받을수 있다.

// T&&   : 임의의 타입의 lvalue 와 rvalue 를 모두 받는다.
//			
// 인자로 n(lvalue)를  보내면   T : int&    T&& a : int&
// 인자로 10(rvalue)를 보내면   T : int     T&& a : int&&

// 결국, f4(int&) 와 f4(int&&) 함수를 생성한다는 것!!

// T&& : "forwarding reference" 라고 부릅니다.
//        "universal reference" 라는 용어는 effective-C++ 저자가
//									초기에 제안한 이름.



void f1(int& ) {}
void f2(int&&) {}

template<typename T> void f3(T&  a) {}

int main()
{
	int n = 0;

	// 1. 사용자가 타입을 명시적으로 지정하는 경우
	f3<int>( n );    // T& : int&     f3(int& a) 인 함수 생성
	f3<int&>(n );    // T& : int& &   f3(int& a) 인 함수 생성
	f3<int&&>(n );   // T& : int&& &  f3(int& a) 인 함수 생성

	// 2. 사용자가 타입을 지정하지 않은 경우 - 대부분 이렇게 사용
	// 함수 인자를 보고 컴파일러가 T 타입을 결정해야 한다.
	f3(n); // ok. T는 int
	f3(10);//컴파일 error
}






template<typename T> void f4(T&& a) {}

int main()
{
	int n = 0;

	// 1. 타입을 명시적으로 전달하는 경우 => 사용자가 어떤 함수를 
	//								생성할지 결정하는 것
	f4<int>(10);	// T&& : int&&      f4(int&& a) 생성
	f4<int&>(n );   // T&& : int& &&    f4(int& a) 생성
	f4<int&&>(10 ); // T&& : int&& &&   f4(int&& a) 생성

	// 2. 타입을 전달하지 않으면 컴파일러가 인자를 보고 타입을 결정해야한다

	f4(n);   // T : int&   T&& : int& && =>int&   a의 타입 : int&
	f4(10);  // T : int    T&& : int &&  =>int&&  a의 타입 : int&&
}




