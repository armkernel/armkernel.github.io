#include <iostream>
#include <type_traits>
using namespace std;

class Shape
{
	virtual void Draw() = 0;
};

// 1. ������ �����ϴ� ��츸 �������� ���� ��쿡 �ٸ� �Լ��� ȣ��ǵ����Ѵ�.
// �߻� Ŭ����
// ��ü�� ����� ����.
// ������ ������ ����� �ִ�.
// �迭�� ����Ű�� �����ʹ� ����� ����.

// 2. � �Լ��� ���õǴ��� Ȯ�θ� �ϸ� �ȴ� "�򰡵��� ���� ǥ����"

template<typename T> char check(T(*)[1]);
template<typename T> int  check(...);

int main()
{
	if ( sizeof(check<Shape>(0) ) == sizeof(char))
		cout << "�߻�ƴ�.." << endl;
	else 
		cout << "�߻�..." << endl;
}



