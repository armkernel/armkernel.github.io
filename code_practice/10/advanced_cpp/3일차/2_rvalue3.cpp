int main()
{
	int n = 10;
	int* p = &n;

	// decltype ��Ģ 1. ���� �̸��� �ִ� ���
	//				    �ش� ������ ������ �����ؼ� Ÿ�԰���
	decltype(n)  d1; // int d1
	decltype(p)  d2; // int* d2

	// decltype ��Ģ 2. ������ �����ڰ� ���Ե� ǥ������ �ִ°��
	//			�ش� ǥ������ ��ȣ�� ���ʿ� �ü� ������ ����
	//			�ƴϸ� �� Ÿ��
	decltype(*p)   d3; // int& d3;   �ʱⰪ�� �����Ƿ� ����
	decltype(n+1)  d4; // int d4;
	decltype(++n)  d5; // int& d5;
	decltype(n++)  d6; // int d6;

	decltype(n)   d7; // int
	decltype(10)  d8; // int
	decltype((n))   d9; // int&
	decltype((10))  d10; // int

}



