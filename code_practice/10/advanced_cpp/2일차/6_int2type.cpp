// 6_int2type1.cpp - 115 page

// template �� 2�� ������ �Ѵ�.
// 1. T�� ���� ���� �κ��� ������ ���� �մϴ�
//    T�� ���� �ִ� �ڵ�� �������� �ʽ��ϴ�.

// 2. ���� ����ϸ� TŸ���� �����ǰ�.. ���� �Լ�(Ŭ����)�� �ڵ尡 ����.
//    ������ �Լ��� �ٽ� ������(��������) �մϴ�.

// "���� : C++ template complete guide 2nd edition"

// �Ʒ� �Լ� �ڵ�� �����ϱ�� ?
template<typename T> void foo(T a)   // void foo(int a)
{
	*a = 10;
	goo(a);
	goo();
}

int main()
{
	//foo(10);
}