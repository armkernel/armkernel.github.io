
// 115 page �ҽ��� �ᱹ �Ʒ� �̾߱� �Դϴ�.
// "Modern C++ Design" å�� ������ "�ȵ巹�� �˷���巹��ť" �� ó��
// �Ұ��� �ڵ�!(2000���)
template<int N> struct int2type
{
	enum { value = N };
};
int main()
{
	foo(0);
	foo(1); // 0, 1�� ���� Ÿ��(int), foo(0), foo(1) �� ���� �Լ� ȣ��

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1); // t0, t1�� �ٸ� Ÿ��. foo(t0), foo(t1) �� �ٸ� �Լ� ȣ��
}
