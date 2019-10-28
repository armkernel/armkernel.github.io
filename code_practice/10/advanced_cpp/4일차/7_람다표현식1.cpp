// 7_람다표현식1.cpp

int main()
{
	// 람다표현식 활용 1. STL 사용시 알고리즘 함수의 인자로 전달
	// sort(x, x + 10, [](int a, int b) { return a < b; });


	// 활용 2. auto 변수에 담아서 함수 처럼 사용.

	auto f = [](int a, int b) { return a + b; };
		// class xxx{}; xxx();

	// 이제 f를 함수 처럼 사용하면 됩니다.
	int n = f(1, 2);

	// 다음중 에러는 모두 고르세요.
	auto   f1 = [](int a, int b) { return a + b; }; //ok. class xx{};xx();
	auto&  f2 = [](int a, int b) { return a + b; }; // error
	auto&& f3 = [](int a, int b) { return a + b; }; // ok


	decltype(f1) f4;     // error until c++17, ok C++20
	decltype(f1) f5(f1); // ok.. 복사 생성자가 제공된다.

	// cppreference.com 에서 첫번째 화면
}





