template<typename T> class Test
{
public:
	void foo(T&& arg) {}

	// �Ʒ� �Լ��� forwarding reference �Դϴ�.
	template<typename U> void goo(U&& arg) {}
};
int main()
{
	pair<int, int> p;
	int n = 10;

	Test<int> t; // �̼��� T�� Ÿ���� �����Ǿ���.. int

	t.foo(n);  // 1. error
	t.foo(10); // 2

	t.goo(n); // ok
	t.goo(10); // ok

	// 1,2 �� ������ ������� ? ������� ?
}