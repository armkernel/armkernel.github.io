// 2_����Ʈ������1

// raw �������� ������
int main()
{
	int* p1 = new int;
	int* p2 = p1;

	// 1. �޸� ���� ����
	// 2. dangling pointer
	delete p1;
	if ( p2 != 0)
		*p2 = 10;  // ������ �޸� ���

	// 3. double delete
	delete p2;
}






