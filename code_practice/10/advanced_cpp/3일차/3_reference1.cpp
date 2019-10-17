// 3_reference1

int main()
{
	int n = 0;

	// 레퍼런스 규칙
	// 1. non const lvalue reference 는 lvalue 만 가리킨다.
	int& r1 = n;	// ok
	int& r2 = 10;	// error


	// 2. const lvalue reference 는 lvalue 와 rvalue를 모두 가리킨다.
	//    단점 : rvalue가 항상 const 인것은 아니다. Point(0,0)
	const int& r3 = n;	// ok
	const int& r4 = 10;	// ok


	// 3. C++11. const 없이 rvalue 가리키는 참조가 필요 했다.
	// rvalue reference 는 rvalue 만 가리킬수 있다.
	int&& r3 = n;	// error
	int&& r4 = 10;	// ok	
	
}




// ARM( Annoted Reference Manual )