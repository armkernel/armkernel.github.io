// 8_value_category
#include <iostream>
using namespace std;

struct Animal
{
	virtual void Cry() { cout << "Animal Cry" << endl; }  // 1
};
struct Dog : public Animal
{
	virtual void Cry() { cout << "Dog Cry" << endl; }  // 2
};

Dog d;

Animal   f1()   // ���ʿ� �ü�����. move ȣ��, non polynmorphic
{
	return d;
}
Animal&& f2()  // ���ʿ� �ü� ����. move ȣ��.  Polymorphic
{
	return move(d); 
}
Animal&  f3()   // ���ʿ� �ü��ִ�. copy ȣ��, polymorphic
{
	return d;
}
int main()
{
	f2();

	f1().Cry(); // Animal Cry
	f2().Cry(); // Dog    Cry
	f3().Cry(); // Dog    Cry

	Dog d1 = f1(); // move
	Dog d2 = f2(); // move
	Dog d3 = f3(); // copy
}

// expression : �ϳ��� ������ ���ɼ� �ִ� �ڵ� ����

// lvalue : ǥ������ ����� lvalue ����
// xvalue : ǥ������ ����� rvalue ����
// prvalue : ǥ������ ����� ��(literal,�ӽð�ü)

f1();  // �� ��ȯ
f2();  // rvalue ���� ��ȯ
f3();  // lvalue ���� ��ȯ

int main()
{
	int n = 10;
	static_cast<int&>(n) = 10; // �޸𸮰� ��ȯ. lvalue����.
	static_cast<int&&>(n) = 10;// �޸𸮰� ������, lvalue �ȵ�.
	n+1 = 10;					// ��(11)��ȯ. lvalue �ȵ�.


	
	Point pt;

	// �Ʒ� �ڵ�� lvalue �� _rvalue(xvalue)_ �� ĳ�����ϰ� �ֽ��ϴ�.
	Point pt2 = static_cast<Point&&>(pt);
	
}





