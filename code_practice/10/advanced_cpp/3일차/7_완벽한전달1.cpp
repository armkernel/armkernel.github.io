// 7_�Ϻ�������1

int main()
{
	int n = 10;

	int*  p1 = &n;
	int* * p2 = &p1; // ������ ������ ������ - ok

	int& r1 = n;
	int& & r2 = n;  // ���۷����� ���۷��� - error
}