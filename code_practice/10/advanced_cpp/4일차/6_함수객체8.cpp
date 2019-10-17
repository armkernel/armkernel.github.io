#include <iostream>
#include <algorithm>
#include <functional> 
using namespace std;

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	sort(x, x + 10); // 무조건 오름 차순

	// 비교정책 변경 1. 일반 함수 사용 - 비교 정책이 치환 안됨. 느리다.
	// sort(x, x + 10, cmp1);

	// 2. 함수 객체 사용
	//greater<int> f;
	//sort(x, x + 10, f);
	
	// 객체() : () 연산자 호출
	// 타입() : 임시객체 생성

	//sort( x, x + 10, greater<int>() ); // 임시객체 사용


	// 3. C++11 부터는 람다 표현식이 좋습니다.

	// [] : lambda introducer.   람다 표현식이 시작됨을 알리는 것
	sort(x, x + 10, [](int a, int b) { return a < b;  } );


	// 위 코드를 보고 컴파일러는 아래 코드를 생성합니다.
	class ClosureType
	{
	public:
		inline bool operator()(int a, int b) const
		{
			return a < b;
		}
	};
	sort(x, x + 10, ClosureType() );






	
	for (int n : x)
		cout << n << endl;
}





