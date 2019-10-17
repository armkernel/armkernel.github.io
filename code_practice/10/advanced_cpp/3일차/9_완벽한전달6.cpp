// 9_�Ϻ�������3
#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}

// ���
// 1. int&, int&& �� 2�� ������ �Ѵ�.
// 2. int&& ���������� �ٸ� �Լ��� �����Ҷ� rvalue �� ĳ�����ؼ� ����
/*
template<typename F> void chronometry(F f, int& arg)
{
	//f(arg);
	f( static_cast<int&>(arg) ); // �ʿ� ���� ĳ����..
								// ������ �־ �������� �ʴ´�.
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/
// n(lvalue)  ���� => T : int&    T&& : int&
// 10(rvalue) ���� => T : int     T&& : int&&
// ��, �Ʒ� ���ø��� 2��° ���ڰ� n ���� 10 ������ ���� ���� 2�� �Լ�����
template<typename F, typename T> void chronometry(F f, T&& arg)
{
	// ���� . �Ʒ� ĳ������ ?
	// 1. lvalue ĳ�����̴�.
	// 2. rvalue ĳ�����̴�.
	// 3. 2��° ���ڰ� �����̳Ŀ� ���� �ٸ� ĳ�����̴�. (��)

	// 2��° ���ڷ� 10(rvalue)�� ������ _rvalue_ �� ĳ����
	// 2��° ���ڷ� n(lvalue)�� ������ _lvalue_ �� ĳ����
	//f(static_cast<T&&>(arg));

	f( std::forward<T>(arg) ); // std::forward() �Լ��� ��ó�� ĳ�����ϰ�
							// �ֽ��ϴ�.
}




int main()
{
	hoo(10);

	chronometry(hoo, 10); 
}




