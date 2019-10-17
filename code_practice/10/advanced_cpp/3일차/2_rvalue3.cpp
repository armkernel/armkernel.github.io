int main()
{
	int n = 10;
	int* p = &n;

	// decltype 규칙 1. 변수 이름만 있는 경우
	//				    해당 변수의 선언을 조사해서 타입결정
	decltype(n)  d1; // int d1
	decltype(p)  d2; // int* d2

	// decltype 규칙 2. 변수에 연산자가 포함된 표현식이 있는경우
	//			해당 표현식이 등호의 왼쪽에 올수 있으면 참조
	//			아니면 값 타입
	decltype(*p)   d3; // int& d3;   초기값이 없으므로 에러
	decltype(n+1)  d4; // int d4;
	decltype(++n)  d5; // int& d5;
	decltype(n++)  d6; // int d6;

	decltype(n)   d7; // int
	decltype(10)  d8; // int
	decltype((n))   d9; // int&
	decltype((10))  d10; // int

}



