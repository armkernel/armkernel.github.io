// 3_�������Լ�
class Rect
{
public:
	int x = 0, y = 0, w = 10, h = 10;

	int setY(int a) { y = a; }

	// �ٽ� . const ��� �Լ��� �ʼ� �����Դϴ�.
	//		��ü�� ���¸� �������� ���� ��� ����Լ���
	//		�ݵ�� ��� ��� �Լ��� �ؾ� �մϴ�.
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





