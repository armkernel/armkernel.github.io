// 4_typename

class AAA
{
public:
	typedef int DWORD;
	static int value;
};
int AAA::value = 0;

template<typename T> void foo(T t)
{
	// �Ʒ� ���� �ؼ��� ������
	AAA::DWORD n; // int n   ok

	//T::DWORD n2; // error DWORD �� static ��� �������� typedef����
				// �˼� ���� ������ error

	// C++ ��Ģ
	// T::�̸�  => ������ static ������ �ؼ�
	// typename T::�̸�  => "�̸�" �� static ������ �ƴ� Ÿ������ 
	//					   �ؼ��� �޶�.
	int n2 = T::value; // ok

	typename T::DWORD n3; // typename�� �ݵ�� �ʿ� �մϴ�.
}


int main()
{
	AAA a;
	foo(a);
}