#include <iostream>
using namespace std;

class Data{};

class Test
{
	Data data;
public:
	// setter �����
	// ��� 1. 2���� �Լ��� �����ϱ� - ���� ���� ���
	//void SetData(const Data& d) { data = d; }
	//void SetData(Data&& d) { data = move(d); }

	// ��� 2. forwarding reference ���
	// T&& : Data& �� Data&&�� �Լ��� �ڵ�����(int�����)
	//     const Data&
	template<typename T> void SetData(T&& d)
	{
		// ������ �´� ���� ?
		//data = d; // 1. �׻� ����
		// move : ���ڸ� �׻� rvalue�� ĳ����
		//data = std::move(d); // 2. const�� �ƴϰ� move �����ڰ�
							// ������ move
		
		// forward : main �Լ����� rvalue�� ������ rvalue ĳ����
		//						  lvalue�� ������ lvalue ĳ����
		data = std::forward<T>(d); // 3
	}
};
int main()
{
	const Data d;
	Test t;
	t.SetData(d);
	t.SetData(move(d));
}





