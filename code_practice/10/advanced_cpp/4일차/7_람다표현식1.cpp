// 7_����ǥ����1.cpp

int main()
{
	// ����ǥ���� Ȱ�� 1. STL ���� �˰��� �Լ��� ���ڷ� ����
	// sort(x, x + 10, [](int a, int b) { return a < b; });


	// Ȱ�� 2. auto ������ ��Ƽ� �Լ� ó�� ���.

	auto f = [](int a, int b) { return a + b; };
		// class xxx{}; xxx();

	// ���� f�� �Լ� ó�� ����ϸ� �˴ϴ�.
	int n = f(1, 2);

	// ������ ������ ��� ������.
	auto   f1 = [](int a, int b) { return a + b; }; //ok. class xx{};xx();
	auto&  f2 = [](int a, int b) { return a + b; }; // error
	auto&& f3 = [](int a, int b) { return a + b; }; // ok


	decltype(f1) f4;     // error until c++17, ok C++20
	decltype(f1) f5(f1); // ok.. ���� �����ڰ� �����ȴ�.

	// cppreference.com ���� ù��° ȭ��
}





