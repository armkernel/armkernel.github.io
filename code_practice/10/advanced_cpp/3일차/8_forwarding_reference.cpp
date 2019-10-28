// 8_forwarding_reference - ���� �߿��մϴ�. C++11 �� �ٽ� ���

// int&  : int Ÿ���� lvalue �� ������ �ִ�.
// int&& : int Ÿ���� rvalue �� ������ �ִ�.
// T&    : ������ Ÿ���� lvalue �� ������ �ִ�.

// T&&   : ������ Ÿ���� lvalue �� rvalue �� ��� �޴´�.
//			
// ���ڷ� n(lvalue)��  ������   T : int&    T&& a : int&
// ���ڷ� 10(rvalue)�� ������   T : int     T&& a : int&&

// �ᱹ, f4(int&) �� f4(int&&) �Լ��� �����Ѵٴ� ��!!

// T&& : "forwarding reference" ��� �θ��ϴ�.
//        "universal reference" ��� ���� effective-C++ ���ڰ�
//									�ʱ⿡ ������ �̸�.



void f1(int& ) {}
void f2(int&&) {}

template<typename T> void f3(T&  a) {}

int main()
{
	int n = 0;

	// 1. ����ڰ� Ÿ���� ��������� �����ϴ� ���
	f3<int>( n );    // T& : int&     f3(int& a) �� �Լ� ����
	f3<int&>(n );    // T& : int& &   f3(int& a) �� �Լ� ����
	f3<int&&>(n );   // T& : int&& &  f3(int& a) �� �Լ� ����

	// 2. ����ڰ� Ÿ���� �������� ���� ��� - ��κ� �̷��� ���
	// �Լ� ���ڸ� ���� �����Ϸ��� T Ÿ���� �����ؾ� �Ѵ�.
	f3(n); // ok. T�� int
	f3(10);//������ error
}






template<typename T> void f4(T&& a) {}

int main()
{
	int n = 0;

	// 1. Ÿ���� ��������� �����ϴ� ��� => ����ڰ� � �Լ��� 
	//								�������� �����ϴ� ��
	f4<int>(10);	// T&& : int&&      f4(int&& a) ����
	f4<int&>(n );   // T&& : int& &&    f4(int& a) ����
	f4<int&&>(10 ); // T&& : int&& &&   f4(int&& a) ����

	// 2. Ÿ���� �������� ������ �����Ϸ��� ���ڸ� ���� Ÿ���� �����ؾ��Ѵ�

	f4(n);   // T : int&   T&& : int& && =>int&   a�� Ÿ�� : int&
	f4(10);  // T : int    T&& : int &&  =>int&&  a�� Ÿ�� : int&&
}




