#include <iostream>
using namespace std;

class A
{
public:
	virtual void foo(int n = 10) { cout << "A " << n << endl; }
};
class B : public A			
{
public:
	virtual void foo(int n = 20) { cout << "B " << n << endl; }
};
int main()
{
	A* p = new B;
	p->foo(); // 결과 예측해 보세요.
			  // B 10
		// p->vtptr[1](10) 라는 기계어 코드 생성

	// 디폴트 파라미터 : 컴파일 시간에 채운다.
	// 가상함수 호출   : 실행시간에 결정

	// 결론 : 가상함수에서 디폴트 파라미터 문법은 사용하지 마세요.

}



