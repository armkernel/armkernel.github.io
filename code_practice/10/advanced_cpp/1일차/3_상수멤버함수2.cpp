// 3_상수멤버함수
class Rect
{
public:
	int x = 0, y = 0, w = 10, h = 10;

	int setY(int a) { y = a; }

	// 핵심 . const 멤버 함수는 필수 문법입니다.
	//		객체의 상태를 변경하지 않은 모든 멤버함수는
	//		반드시 상수 멤버 함수로 해야 합니다.
	int getArea()  const
	{
		return w * h;
	}
};
void foo(const Rect& r)
{
	int n = r.getArea(); // error
}
int main()
{
	Rect r;
	int n = r.getArea(); // ok

	foo(r);

}





