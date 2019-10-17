// 1_완벽한전달
#include <iostream>
#include <vector>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b)  : x(a), y(b) { cout << "Point()" << endl; }
	
	Point(const Point& p): x(p.x), y(p.y)
	{ 
		cout << "Point(const Point&)" << endl; 
	}
	~Point() { cout << "~Point()" << endl; }
};
int main()
{
	vector<Point> v;

	// v 에 1,2 로 초기화된 Point를 넣고 싶습니다.
	// 1. Point 객체 생성후 넣기 - 1개의 객체가 생성됨.
	//Point p1(1, 2);
	//v.push_back(p1);

	// 2. 방법 2
	// 2개의 객체, move 생성자로 복사
	//Point p1(1, 2);
	//v.push_back(move(p1));

	// 3. 방법 3. 임시객체 사용
	// 2개의 객체, move 생성자, 임시객체 이므로 문장의 끝 파괴
	//v.push_back(Point(1, 2));

	// 방법 4. 객체를 외부에서 만들지 말고 vector가 직접 만들게
	//        한다.
	//        단, 객체를 만들때 필요한 생성자 인자 전달
	//v.emplace_back(1, 2); // 이 함수가 내부적으로
						  // new Point(1,2)

//	v.push_back({ 1,2 }); // 임시객체를 생성하는 코드!
							// 아래 원리!
//	const Point& p = { 1,1 }; // 

	cout << "--------" << endl;
}