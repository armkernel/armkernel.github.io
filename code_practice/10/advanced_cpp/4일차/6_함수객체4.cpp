// 6_함수객체4

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }
inline int Sub(int a, int b) { return a - b; }

// 1. 인라인 함수는 컴파일 시간에 이루어지는 문법이다.
// 2. 인라인 함수라도 함수 포인터에 담아서 호출하면 치환될수 없다.


void foo( int(*f)(int, int) )
{
	int n = f(1, 2);
}

int main()
{
	Add1(1, 2); // 호출
	Add2(1, 2); // 치환. 빠르다.

	int(*f)(int, int) = &Add2;

	//if (사용자입력 == 1) f = &Add1;

	f(1, 2);

	foo(Add2);
	foo(Add1);
}



