// 3_�������Լ�
class Rect
{
public:
	int x = 0, y = 0, w = 10, h = 10;

	int setY(int a) { y = a; }

	int getArea() const  // ��� ��� �Լ�!! �߿�!
	{
		//w = 20; // error. ��� ��� �Լ� �ȿ����� ��� �����
			      // ��� ���(�б⸸ ����)
		return w * h;
	}
};
int main()
{
	const Rect r; // �����ڷ� �ʱ�ȭ �ߴٰ� ����..
	
	r.x = 10;  // error. const ��ü �̹Ƿ�!!
	r.setY(10);// error.

	r.getArea(); // error. ȣ�� �ɼ� �ְ� �Ϸ���
				// �ݵ�� getArea()�� ��� ��� �Լ��� �ؾ� �Ѵ�.

				// ��� ��ü�� ��� ��� �Լ��� ȣ���Ҽ� �ִ�.
}





