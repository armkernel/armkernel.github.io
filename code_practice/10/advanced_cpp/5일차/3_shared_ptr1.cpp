// 3_shared_ptr1
#include <iostream>
using namespace std;

// 1. ��� ����
#include <memory>

class Car
{
public:
	void Go() { cout << "Car Go" << endl; }
	~Car() { cout << "~Car" << endl; }
};

int main()
{
	// 2. �����ڰ� explicit �̹Ƿ� = �δ� �ʱ�ȭ �ȵ�.
	//shared_ptr<int> sp1 = new int; // error
	shared_ptr<int> sp2( new int); // ok..

	// 3. ũ�� : ��κ��� �������� raw pointer * 2
	cout << sizeof(sp2) << endl;

	// 4. -> �� . ����
	shared_ptr<Car> sp3(new Car);

	// -> : ���ü�� ��� �Լ�
	sp3->Go();

	// . : shared_ptr ��ü�� ��� �Լ�
	int n = sp3.use_count(); // ���� ��� ������
	cout << n << endl; // 1

	Car* p = sp3.get(); // raw pointer

	sp3.reset(); // if ( --������� == 0 ) delete; obj == nullptr;
}