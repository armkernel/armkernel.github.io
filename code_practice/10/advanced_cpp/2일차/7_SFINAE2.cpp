// 7_SFINAE - 215page
#include <iostream>
using namespace std;

//void foo(int a)    { cout << "int"    << endl; }


// 1. foo(10) => ���ø� ������ ����ϱ�� ����

// 2. T::type �� int::type ���� ġȯ�ϴ�. �߸��� ǥ���� ����
//    �����Ͽ����� �ƴϰ� �ĺ������� ���� �ȴ�.

// 3. �ٸ� ������ foo �� ������ ��밡��. 

// "ġȯ���д� ������ �ƴϴ�" 

// "Substitution Failure Is Not An Error" => SFINAE


template<typename T>
typename T::type foo(T a)  { cout << "T" << endl; return 0; }
// int::type

void foo(...) { cout << "..." << endl; }

int main()
{
	foo(10); 
}

