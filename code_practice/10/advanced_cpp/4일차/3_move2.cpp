#include <iostream>
using namespace std;

class Point
{
public:
	Point(int a, int b) {}
	Point(const Point& p) { cout << "copy" << endl; }
	Point(Point&& p)      { cout << "move" << endl; }
};

// ���ø��� ���鶧 ���ڸ� T& �� �Ұ��ΰ� T&& �Ұ��ΰ� ? 
// T& : lvalue �� �ްڴ�
// T&& : lvalue �� rvalue ��� �ްڴ�
/*
template<typename T> T&& xmove(T&& arg)
{
	// xmove(lvalue) : T �� int&
	// xmove(rvalue) : T �� int
	// �� �Ʒ� ĳ������ rvalue ĳ������ �ƴ� ��Ȳ�� ���� �޶����� ĳ����
	return static_cast<T&&>(arg);
}
*/

template<typename T> remove_reference_t<T> && xmove(T&& arg)
//template<typename T> decltype(auto) xmove(T&& arg)
{
	return static_cast<remove_reference_t<T> &&>(arg);
}

int main()
{
	Point p1(1, 2);
	Point p2 = p1; // copy
	Point p3 = static_cast<Point&&>(p2); // move
	Point p4 = move(p3); // move
	Point p5 = xmove(Point(1,2)); // move


	// �Ʒ� �Լ��� � �����ڸ� ȣ���ұ�� ?
	// 1. ���ڰ� 2���λ�����
	// 2. ���� ������
	// 3. move ������

	Point pt = Point(1, 2); //
	// C++98 : �ӽð�ü�� ����� ���� �����ڷ� pt�� ����
	// C++11 : �ӽð�ü�� ����� Move �����ڷ� pt�� move
	//  ������ ���� �����Ϸ��� ����ȭ �ϸ鼭 ���� ������, move������
	//  ȣ���� ����!!
	// C++17 : ���������� �ӽð�ü�� ������ �ʰ� ���� 2�� ������ȣ��

	// gcc a.cpp -std:c++98 -fno-elide-constructos
	// gcc a.cpp -std:c++17 -fno-elide-constructos
	// gcc a.cpp -std:c++11 -fno-elide-constructos

}


