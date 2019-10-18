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
// make_shared의 원리를 생각해 봅시다
template<typename T, typename ... ARGS> 
shared_ptr<T> make_shared(ARGS&& ... args )
{
	void* p = operator new(sizeof(T) + sizeof(관리객체));

	// 객체 부분 생성자 호출
	new(p) T( std::forward<ARGS>(args)...);

	// 관리객체 부분 생성자 호출.
	//.... 
	shared_ptr<T> sp;
	sp.reset(p, ((char*)p) + sizeof(T));
	return sp;
}
*/
int main()
{
	// 아래 코드는 동적 메모리 할당을 몇번 하게 될까요 ?
	// 2번 할당 : 객체 할당, 관리객체 할당
	//shared_ptr<Point> sp1(new Point(1, 2));

	// sizeof(객체) + sizeof(관리객체)로 한번에 할당합니다.
	shared_ptr<Point> sp2 = make_shared<Point>(1, 2);

	// make_shared 장점
	// 1. 객체 + 관리객체를 한번에 할당하므로 "메모리 파편화" 현상이 줄어든다.
	// 2. 안전하다.

	foo(shared_ptr<int>(new int), goo() ); // 1. new int
											// 2. goo()
											// 3. shared_ptr만들기
				// 순서로 실행되고 goo에서 예외가 나오면 메모리 누수

	foo(make_shared<int>(), goo()); // 메모리 누수는 없다!

	foo(new int, goo()); // 좋을까요 ? 나쁠까요 ? => 나쁜 코드!
}

void foo(shared_ptr<int> sp, int n) {} // shared_ptr<int> sp = new int











