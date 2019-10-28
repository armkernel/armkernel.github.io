// 1_checked_delete - 37 page

#include <iostream>

using namespace std;

class Point; // 클래스 전방 선언 (forward declration)
             // 완전한 선언이 있어도 포인터 변수는 만들 수 있다.
             // 전방 선언 되어있으면, 4byte라는 정도만 알 수 있다.
             // 따라서, 클래스 내 멤버변수는 클래스를 만나기 전에.. 멤버 변수를 사용할 수 없다.

// incomplete type
// incomplete type 이 delete 하면, 소멸자가 호출 되지 않는 문제가 있다.

void foo(Point* p)
{
  default_delete<int> d; 
  // sizeof(Point); // incomplete type은 크기를 구할 수 없다.
                 // 옛날 컴파일러들은 삭제하는 경향이 있다. <- 최적화
                 // 그래서 뭘 받아야 안지워짐.
                 // 근데 의미 있게 하기 위해서 enum을 사용함
                 // int a = sizeof (Point);
                 //
  enum { type_must_be_complete = sizeof(int) }; //예전 안드로이드 소스 (주석 같은 의미)

  static_assert( sizeof(Point) > 0, "type is incomplete" ); // 정적 디버깅

  delete p;
}

class Point
{
  int x,y;
public:
  Point() { cout << "Point()" << endl; }
  ~Point() { cout << "~Point()" << endl; }
};

int main()
{
  Point* p1 = new Point;
  foo(p1);
}
