// 6_�Լ���ü4

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }
inline int Sub(int a, int b) { return a - b; }

// 1. �ζ��� �Լ��� ������ �ð��� �̷������ �����̴�.
// 2. �ζ��� �Լ��� �Լ� �����Ϳ� ��Ƽ� ȣ���ϸ� ġȯ�ɼ� ����.


void foo( int(*f)(int, int) )
{
	int n = f(1, 2);
}

int main()
{
	Add1(1, 2); // ȣ��
	Add2(1, 2); // ġȯ. ������.

	int(*f)(int, int) = &Add2;

	//if (������Է� == 1) f = &Add1;

	f(1, 2);

	foo(Add2);
	foo(Add1);
}



