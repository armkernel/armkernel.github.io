// 77 page 이야기.. 

// C++11 부터 enable_if 는 표준 입니다. 아래처럼 만들어져 있습니다.
template<bool b, typename T = void> struct enable_if
{
	typedef T type;
};

template<typename T> struct enable_if<false, T>
{
};

int main()
{
	// n1 ~ n4의 타입을 예측해 보세요.
	enable_if<true, int>::type    n1; // int
	enable_if<true, double>::type n2; // double
	enable_if<true, void>::type         n3; // void, 단 void변수는 만들수없다
										// error

	enable_if<false,int>::type    n4;// error. ::type 멤버가 없다
}