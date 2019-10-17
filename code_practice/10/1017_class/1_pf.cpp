// 완벽한 전달
//
#include <iostream>
#include <vector>
using namespace std;

class Point
{
  int x,y;
public:
  Point(int a, int b) : x(a), y(b) { cout << " Point() " << endl; }
  Point(const Point& p) : x(p.x), y(p.y) 
  {
    cout << "Point(const Point&) " << endl;
  }
  ~Point() { cout << " ~Point() "<< endl; }
};

int main()
{
  vector<Point> v;

  // v 에 1,2로 초기화 된 Point를 넣고 싶습니다.
  // 1. Point 객체 생성 후 넣기 

  // Point p1 (1,2);
  // v.push_back(p1); // 복사본 만든다.
  // vector 내부에서 복사 일어남.
  /*
   *  Point()
      Point(const Point&)
       ---------
       ~Point()
       ~Point()
   * */
  // 방법 2.
  // v.push_back(move(p1)); // 약간 속도가 빨라짐.
  // 우리는 move를 만들지 않음
  //
  // 방법 3.
  //v.push_back(Point(1,2));
  // 두개의 객체인데.. move 로 감.

  // 전달하려고 만든건데.. 두개를 만들필요가?
  // 하나 만들어.. 내가 밖에서 만들면 별로니까.
  // 너가 만들어.. emplace_back
  //
  //방법 4.
  // 왜 완벽한 전달을 써야하지? 
  v.emplace_back(1,2); // 이 함수가 내부적으로
                       // new Point(1,2)
                       // 생성자의 인자는 어떻게 생겼는지 되게 많다.
                       // 따라서, perfect forwarding을 써야함.
                       // 예를들어 인자에 &가 있다면, 문제가 된다.
  // 생성자 한번, 소멸자 한번                     
  cout << "---------" << endl;
}
