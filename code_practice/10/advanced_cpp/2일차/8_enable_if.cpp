// 77 page �̾߱�.. 

// C++11 ���� enable_if �� ǥ�� �Դϴ�. �Ʒ�ó�� ������� �ֽ��ϴ�.
template<bool b, typename T = void> struct enable_if
{
	typedef T type;
};

template<typename T> struct enable_if<false, T>
{
};

int main()
{
	// n1 ~ n4�� Ÿ���� ������ ������.
	enable_if<true, int>::type    n1; // int
	enable_if<true, double>::type n2; // double
	enable_if<true, void>::type         n3; // void, �� void������ ���������
										// error

	enable_if<false,int>::type    n4;// error. ::type ����� ����
}