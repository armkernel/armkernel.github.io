int main()
{
	typedef int&  LREF;
	typedef int&& RREF;

	int n = 10;

	LREF r1 = n;
	RREF r2 = 10;

	// typedef �� ���ø��� ���� reference �� reference ����
	// reference collapsing( ���۷��� �ر�(���) )
	LREF& r3 = n ; // int& &  => &
	RREF& r4 = n ; // int&& & => &

	LREF&& r5 = n ; // int& && => &
	RREF&& r6 = 10 ; // int&& && => &&
}

