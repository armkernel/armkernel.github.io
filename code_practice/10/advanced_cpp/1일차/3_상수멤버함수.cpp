// 3_상수멤버함수
class Rect
{
public:
	int x = 0, y = 0, w = 10, h = 10;

	int setY(int a) { y = a; }

	int getArea() const  // 상수 멤버 함수!! 중요!
	{
		//w = 20; // error. 상수 멤버 함수 안에서는 모든 멤버를
			      // 상수 취급(읽기만 가능)
		return w * h;
	}
};
int main()
{
	const Rect r; // 생성자로 초기화 했다고 가정..
	
	r.x = 10;  // error. const 객체 이므로!!
	r.setY(10);// error.

	r.getArea(); // error. 호출 될수 있게 하려면
				// 반드시 getArea()를 상수 멤버 함수로 해야 한다.

				// 상수 객체는 상수 멤버 함수만 호출할수 있다.
}





