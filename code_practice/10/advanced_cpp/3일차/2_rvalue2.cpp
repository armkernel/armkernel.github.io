
// 핵심 : value category 는 객체가 아닌 표현식(expression)에 대한
//		개념입니다.
// statement : ; 으로 종료되는 한줄의 코드 모음
// expression : 하나의 값으로 계산될수 있는 코드 모음.
int main()
{
	int n = 10;

	n = 20; // ok   n 은 lvalue
	n + 1 = 20; // error  n + 1 은 rvalue
	n + n = 20; // error  n + n 은 rvalue

	n = 3;
	++n = 20;	 // ok.. lvalue
				//중요 : 어떤 연산자의 결과가 
				//		"값" 일지 "참조"일지를 잘 생각해야 합니다.
	n++ = 20;  // error. rvalue


	n = 3;
	int s = ++n * ++n;
	cout << s << endl; // 25
}
// 전위형 ++을 만들어 봅시다.
int& operator++(int& n)
{
	n = n + 1;
	return n;
}
// 후위형 ++
int operator++(int& n, int)
{
	int temp = n;
	n = n + 1;
	return temp;
}


