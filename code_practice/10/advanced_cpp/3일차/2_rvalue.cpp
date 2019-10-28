//2_rvalue1.cpp
int x = 0;
int  foo() { return x; }
int& goo() { return x; }

// lvalue : ��ȣ�� ���ʿ� �ü� �ִ� ǥ���(�����ʿ��� �ü� �ִ�.
//			lvalue to rvalue conversion
//			���� �ƴ϶� �̸�(�޸�)�� ������, ���Ͻ��� �Ѿ ����
//			�ּҿ����ڷ� �ּҸ� ���Ҽ� �ִ�
//			������ ��ȯ �ϴ� �Լ�

// rvalue : ��ȣ�� �����ʿ��� �ü� �ִ�.
//		    �̸�(�޸�)�� ����, ���ϽĿ����� ����
//			�ּҿ����ڷ� �ּҸ� ���Ҽ� ����
//			���� ��ȯ�ϴ� �Լ�. 
//			"Temporary", ���ڿ��� ������ literal
int main()
{
	int v1 = 10, v2 = 10;	

	v1 = 20; // v1 : lvalue   20 : rvalue
	10 = v1;
	v2 = v1;

	int* p1 = &v1;
	int* p2 = &10;

	foo() = 10; // error
	goo() = 10; // ok

	const int c = 10;
	c = 20; // error..  c�� lvalue ? rvalue ?
			// immutable lvalue ��� �մϴ�.

	// ������ �´� ���� ?
//	char* s1 = "hello";		// error. ������ C �����Ϸ��� ���
							// ���� C++ �����Ϸ��� ���
//	*s1 = 'a';
	const char* s2 = "hello"; // ok


	10; // rvalue
	"hello"; // ���ڿ� literal�� lvalue

	"hello"[0] = 'a'; //���� �����Ϸ��� C �����Ϸ��� ���
					// ������ const char[] �̹Ƿ� ����

	
}

