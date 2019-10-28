#include <iostream>
#include <memory>

using namespace std;

class Point
{
  int x, y;  
public:
  Point(int a = 0, int b = 0) : x(a), y(b) { cout << " Point() " << endl; }
  ~Point() { cout << " ~Point() " << endl; }
};

void* operator new(size_t sz)
{
  cout << "new : " << sz << endl;

  return malloc(sz);
}

/*
// make_shared 원리를 생각해보자.
template<typename T, typename ... ARGS>
shared_ptr<T> make_shared(ARGS&& ... args )
{
  void* p = operator new ( sizeof(T) + sizeof(관리객체) );
  // 메모리 할당 먼저 

  // 생성자에게 전달해야함.
  // 완벽한 전달
  new(p) T (std::forward<ARGS>(args)...);

  // 관리 객체 부분 생성자 호출
  // 
  shared_ptr<T> sp;
  sp.reset(p, ((char*)p) + sizeof(T) ); // reset은 관리객체 주소..  
}
*/

int main()
{
  //아래의 코드는 동적메모리 할당을 몇 번 할까?
  // 2번 할당 
  //  객체 할당, 관리 객체 할당
  // shared_ptr<Point> sp1(new Point(1,2));
  // 우리의 객체 한번
  // 관리 객체 한번
  // 1. 참조계수
  // 2. 소멸자 주소

  // 떨어 뜨리는 것 보다. => fragmentation/
  // 붙어있는게 좋아
  //
  // sizeof(객체) + sizeof(관리객체) 로 한번에 할당
  shared_ptr<Point> sp2 = make_shared<Point>(1,2);
  // 객체 크기에 관리객체의 크기를 더 해서 한번에 할당
  // 관리 객체에 진짜 주소 포인터도 관리하기 때문에 오히려 크기가 줄어듬
  // memory fragmentation이 줄어든다.
  //

  // make_shared 장점
  // 1. 객체 + 관리 객체를 한번에 할당하므로 "메모리 파편화" 현상이 줄어든다.
  // 2. 안전하다.

  foo( shared_ptr<int>(new int), goo() );

  // goo() int를 반환
  // undefined 어디서부터 함수가 먼저 시작될지 모름.
  // new int 과 goo() 중에 뭐가 먼저 일어나>?
  // undefined..
  //
  // 이건 메모리 누수가 발생할 수 있다.
  // new연산을 하고 바로 shared안하고 goo()를 호출 할 경우
  // exception이 났다고 가정해보자.. 그럼.. 메모리 회수 안되서 누수가 발생.
  
  foo(make_shared<int>(), goo()); // 메모리 누수는 없다.

  foo(new int, goo()); // 좋지 않은 코드..
                       // 나쁜 코드!

}

void foo(shared_ptr<int> sp, int n) {} 
// shared_ptr<int> sp = new int;
