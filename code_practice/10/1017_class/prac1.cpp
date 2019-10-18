#include <iostream>
using namespace std;

class Point
{
  int x,y;
public:
  Point() { cout << "Point" << endl; }
  Point(const Point& copy) { cout << "Point(const Point&)" << endl; }
  Point(Point&& move) { cout << "Point(Point&&) " << endl; }
  ~Point() { cout << "~Point" << endl; }
};

#include <vector>

int main()
{
  //vector<Point> v;
  //Point p1;
  // Point p2(p1);
  //
  // v.push_back(Point());

  // point(point) ? 이건 안되나?
  //
  Point p3{Point{}};


  // Point p3(move(p1));
  //
  // Point p3(Point(1,2));

  cout << "------------------" << endl;
}
