// ����1_this
class Base
{
public:
	void foo() {}
};
class Point : public Base
{
	int x, y;
public:
	void set(int a, int b) // void set(Point* this, int a, int b)
	{
		x = a; // this->x = a;
		y = b; // this->y = b;
	}
	// ��� ��� �Լ��ȿ��� this�� ��� ��ü�� ����Ű�� ������ �̴�.
	int getX() const // int getX(const Point* this)
	{
		//x = 10; // this->x = 10; // error
		return x; 
	}
};
int main()
{
	Point p1, p2;

	p1.set(10, 20); // set(&p1, 10, 20)
	p2.set(30, 40); // set(&p2, 30, 40)
	p1.getX();      // getX(&p1)
}

