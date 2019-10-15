#include <iostream>

using namespace std;

class Point
{
  int x, y;
public:
  Point(int a , int b ) : x(a), y(b)
  {
    cout << "Point()" << endl;
  }
  ~Point() { cout << "~Point()" << endl; }
};

int main()
{
  // 우리가 왜 이런 placement new를 써야하는가?
  // 그거에 대한 예시.
  // Point에 default 생성자가 없다고 가정하자.

  // Point 객체 하나를 힙영역에 생성하는 코드이다.
  Point* p1 = new Point(0,0);

  // 힙 영역에서 10개의 객체를 할당받고 싶다면 어떻게 해야하나?
  // Point* p2 = new Point[10]; 
  // 위와 같이 하게 된다면, default 생성자를 무조건 생성해야한다. 없으면 오류가 난다.
  // 이럴 경우 두 가지 방법이 있다.
  //  1. init-brace 초기화 방법을 이용해 일일히 초기화 하는 방법
  //    - 이 방법 같은 경우 우선 갯수가 많아지면 하기 힘들다.
  //  2. 할당 영역과 객체 초기화영역을 서로 나누어라.
  //    - 우선 객체를 담을 수 있는 영역을 할당 한 후
  //    - 적절한 생성자를 호출하면 된다.

  // 할당하는 방법
  // void* 와 동일하기 때문에 무조건 casting이 필요하다.
  /*
   *  ------
   *  |----|
   *  |----|
   *  |----|
   *  ------
   *  위와 같은 형태로 먼저 메모리 공간을 할당
   * */
  Point* p3 = static_cast<Point*>(operator new(sizeof(Point)* 10));

  for (int i = 0; i < 10; i++)
  {
    // 함수에 주소를 전달.. 여기에 생성자를 불러줘
    // new()
    new (&p3[i]) Point(0,0);
  }

  // 사용후에는 소멸자를 호출
  // 소멸자를 먼저 호출한다.

  for (int i = 0; i < 10; i++)
  {
    p3[i].~Point();
  }

  // 메모리 해제.
  operator delete(p3);
}
