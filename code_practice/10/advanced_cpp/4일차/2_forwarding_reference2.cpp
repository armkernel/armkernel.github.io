template<typename T> class Test
{
public:
	void foo(T&& arg) {}

	// 아래 함수가 forwarding reference 입니다.
	template<typename U> void goo(U&& arg) {}
};
int main()
{
	pair<int, int> p;
	int n = 10;

	Test<int> t; // 이순간 T의 타입이 결정되었다.. int

	t.foo(n);  // 1. error
	t.foo(10); // 2

	t.goo(n); // ok
	t.goo(10); // ok

	// 1,2 는 에러가 있을까요 ? 없을까요 ?
}