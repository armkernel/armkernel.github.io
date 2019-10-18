// 2_스마트포인터1

// raw 포인터의 문제점
int main()
{
	int* p1 = new int;
	int* p2 = p1;

	// 1. 메모리 누수 문제
	// 2. dangling pointer
	delete p1;
	if ( p2 != 0)
		*p2 = 10;  // 삭제된 메모리 사용

	// 3. double delete
	delete p2;
}






