//2_rvalue1.cpp
int x = 0;
int  foo() { return x; }
int& goo() { return x; }

// lvalue : 등호에 왼쪽에 올수 있는 표기법(오른쪽에도 올수 있다.
//			lvalue to rvalue conversion
//			값뿐 아니라 이름(메모리)을 가지고, 단일식을 넘어서 존재
//			주소연산자로 주소를 구할수 있다
//			참조를 반환 하는 함수

// rvalue : 등호에 오른쪽에만 올수 있다.
//		    이름(메모리)이 없고, 단일식에서만 존재
//			주소연산자로 주소를 구할수 없다
//			값을 반환하는 함수. 
//			"Temporary", 문자열을 제외한 literal
int main()
{
	int v1 = 10, v2 = 10;	

	v1 = 20; // v1 : lvalue   20 : rvalue
	10 = v1;
	v2 = v1;

	int* p1 = &v1;
	int* p2 = &10;

	foo() = 10; // error
	goo() = 10; // ok

	const int c = 10;
	c = 20; // error..  c는 lvalue ? rvalue ?
			// immutable lvalue 라고 합니다.

	// 다음중 맞는 것은 ?
//	char* s1 = "hello";		// error. 하지만 C 컴파일러는 허용
							// 옛날 C++ 컴파일러도 허용
//	*s1 = 'a';
	const char* s2 = "hello"; // ok


	10; // rvalue
	"hello"; // 문자열 literal은 lvalue

	"hello"[0] = 'a'; //옛날 컴파일러나 C 컴파일러는 허용
					// 요즘은 const char[] 이므로 에러

	
}

