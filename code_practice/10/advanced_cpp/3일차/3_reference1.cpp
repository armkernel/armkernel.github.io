// 3_reference1

int main()
{
	int n = 0;

	// ���۷��� ��Ģ
	// 1. non const lvalue reference �� lvalue �� ����Ų��.
	int& r1 = n;	// ok
	int& r2 = 10;	// error


	// 2. const lvalue reference �� lvalue �� rvalue�� ��� ����Ų��.
	//    ���� : rvalue�� �׻� const �ΰ��� �ƴϴ�. Point(0,0)
	const int& r3 = n;	// ok
	const int& r4 = 10;	// ok


	// 3. C++11. const ���� rvalue ����Ű�� ������ �ʿ� �ߴ�.
	// rvalue reference �� rvalue �� ����ų�� �ִ�.
	int&& r3 = n;	// error
	int&& r4 = 10;	// ok	
	
}




// ARM( Annoted Reference Manual )