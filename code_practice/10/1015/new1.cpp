#include <iostream>

using namespace std;

class Point
{
  int x, y;
public:
  Point(int a = 0, int b = 0) : x(a), y(b)
  {
    cout << "Point()" << endl;
  }
  ~Point() { cout << "~Point()" << endl; }
};

int main()
{
  // Point *p1 = new Point(1,2);
  // 이렇게 하면 문제가 있음
  //  디폴트 생성자가 아니면, 호출하기 힘듬.
  //  Point* p1 = new Point[10]; // 10개 할당가능.. 하지만, 한번에 불가능
  // 할당과 생성자 호출을 나누자.
  //
  Point* p1 = static_cast<Point*>(operator new(sizeof(Point)));

  cout << p1 << endl;

  // 할당 된 메모리에 생성자를 호출 - placement new 라는 기법
  // 생성자를 불러야 객체가 생성된다.
  new(p1) Point(1,2);

  p1->~Point(); // 메모리 해제 없이 소멸자 호출
  
  operator delete(p1);

}
