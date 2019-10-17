
// �ٽ� : value category �� ��ü�� �ƴ� ǥ����(expression)�� ����
//		�����Դϴ�.
// statement : ; ���� ����Ǵ� ������ �ڵ� ����
// expression : �ϳ��� ������ ���ɼ� �ִ� �ڵ� ����.
int main()
{
	int n = 10;

	n = 20; // ok   n �� lvalue
	n + 1 = 20; // error  n + 1 �� rvalue
	n + n = 20; // error  n + n �� rvalue

	n = 3;
	++n = 20;	 // ok.. lvalue
				//�߿� : � �������� ����� 
				//		"��" ���� "����"������ �� �����ؾ� �մϴ�.
	n++ = 20;  // error. rvalue


	n = 3;
	int s = ++n * ++n;
	cout << s << endl; // 25
}
// ������ ++�� ����� ���ô�.
int& operator++(int& n)
{
	n = n + 1;
	return n;
}
// ������ ++
int operator++(int& n, int)
{
	int temp = n;
	n = n + 1;
	return temp;
}


