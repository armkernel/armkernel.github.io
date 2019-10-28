#include <iostream>
#include <memory>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};
void* operator new(size_t sz)
{
	cout << "new : " << sz << endl;

	return malloc(sz);
}
/*
// make_shared�� ������ ������ ���ô�
template<typename T, typename ... ARGS> 
shared_ptr<T> make_shared(ARGS&& ... args )
{
	void* p = operator new(sizeof(T) + sizeof(������ü));

	// ��ü �κ� ������ ȣ��
	new(p) T( std::forward<ARGS>(args)...);

	// ������ü �κ� ������ ȣ��.
	//.... 
	shared_ptr<T> sp;
	sp.reset(p, ((char*)p) + sizeof(T));
	return sp;
}
*/
int main()
{
	// �Ʒ� �ڵ�� ���� �޸� �Ҵ��� ��� �ϰ� �ɱ�� ?
	// 2�� �Ҵ� : ��ü �Ҵ�, ������ü �Ҵ�
	//shared_ptr<Point> sp1(new Point(1, 2));

	// sizeof(��ü) + sizeof(������ü)�� �ѹ��� �Ҵ��մϴ�.
	shared_ptr<Point> sp2 = make_shared<Point>(1, 2);

	// make_shared ����
	// 1. ��ü + ������ü�� �ѹ��� �Ҵ��ϹǷ� "�޸� ����ȭ" ������ �پ���.
	// 2. �����ϴ�.

	foo(shared_ptr<int>(new int), goo() ); // 1. new int
											// 2. goo()
											// 3. shared_ptr�����
				// ������ ����ǰ� goo���� ���ܰ� ������ �޸� ����

	foo(make_shared<int>(), goo()); // �޸� ������ ����!

	foo(new int, goo()); // ������� ? ���ܱ�� ? => ���� �ڵ�!
}

void foo(shared_ptr<int> sp, int n) {} // shared_ptr<int> sp = new int











