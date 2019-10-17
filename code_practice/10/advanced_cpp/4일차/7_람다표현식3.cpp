#include <iostream>
using namespace std;


class Test
{
public:
	void hoo(int a) { cout << "Test::hoo" << endl; }
};


void goo(int a, int b) { cout << "goo" << endl; }


template<typename T, typename ... ARGS> 
void foo(T&& f, ARGS&& ... args )
{
	//f( std::forward<ARGS>(args)...);
	invoke( std::forward<T>(f) , std::forward<ARGS>(args)...);
}

int main()
{
	foo(goo, 1, 2);

	Test test2;
	foo(&Test::hoo, &test2, 10); // ok..



	// ��� �Լ� ������ ����� ���
	void(Test::*f)(int) = &Test::hoo; // �ٽ� 1. 

	//f(10); // error. ��ü�� ����.

	Test test;
	//test.f(10); // error. f��� ��� �Լ��� ����.

	//test.*f(10); // .* ������ (pointer to member )
				// �켱���� ������ error

	(test.*f)(10); // �ٽ� 2. ��� �Լ� �����ͷ� �Լ� ȣ���ϴ� �ڵ�

	// �� �ڵ尡 �������� ? �Ʒ� �ڵ尡 �������� ?
	//f(&test, 10); // ���� ����.. ������ ����..

	// �׷��� invoke �� ���� ����. c++17
	invoke(f, &test, 10);
}



