#include <iostream>
using namespace std;

class Data{};

class Test
{
	Data data;
public:
	// setter 만들기
	// 방법 1. 2개의 함수를 제공하기 - 가장 좋은 방법
	//void SetData(const Data& d) { data = d; }
	//void SetData(Data&& d) { data = move(d); }

	// 방법 2. forwarding reference 사용
	// T&& : Data& 와 Data&&의 함수를 자동생성(int라고가정)
	//     const Data&
	template<typename T> void SetData(T&& d)
	{
		// 다음중 맞는 것은 ?
		//data = d; // 1. 항상 복사
		// move : 인자를 항상 rvalue로 캐스팅
		//data = std::move(d); // 2. const가 아니고 move 생성자가
							// 있으면 move
		
		// forward : main 함수에서 rvalue를 보내면 rvalue 캐스팅
		//						  lvalue를 보내면 lvalue 캐스팅
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





