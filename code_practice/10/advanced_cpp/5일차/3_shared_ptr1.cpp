// 3_shared_ptr1
#include <iostream>
using namespace std;

// 1. 헤더 파일
#include <memory>

class Car
{
public:
	void Go() { cout << "Car Go" << endl; }
	~Car() { cout << "~Car" << endl; }
};

int main()
{
	// 2. 생성자가 explicit 이므로 = 로는 초기화 안됨.
	//shared_ptr<int> sp1 = new int; // error
	shared_ptr<int> sp2( new int); // ok..

	// 3. 크기 : 대부분의 구현에서 raw pointer * 2
	cout << sizeof(sp2) << endl;

	// 4. -> 와 . 연산
	shared_ptr<Car> sp3(new Car);

	// -> : 대상체의 멤버 함수
	sp3->Go();

	// . : shared_ptr 자체의 멤버 함수
	int n = sp3.use_count(); // 참조 계수 꺼내기
	cout << n << endl; // 1

	Car* p = sp3.get(); // raw pointer

	sp3.reset(); // if ( --참조계수 == 0 ) delete; obj == nullptr;
}