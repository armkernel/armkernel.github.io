// 1. 일반 함수는 자신만의 타입이 없습니다.!!
//    signature가 동일 하면 모두 같은 타입 입니다.

// 2. 함수 객체는 자신만의 타입이 있다.
//   signature 가 동일해도 모든 함수 객체는 다른 타입이다.

struct Plus
{
	inline int operator()(int a, int b) { return a + b; }
};
struct Minus
{
	inline int operator()(int a, int b) { return a - b; }
};
//-----------------------------------------

//void foo(Plus p)
// 인자로 다양한 정책(함수)를 보낼수 있는데,
// 정책이 인라인 치환이 가능한 코드.. 
// 함수객체 + 템플릿으로 만드는 기술
template<typename T> void foo(T p)
{
	int n = f(1, 2);
}

int main()
{
	Plus  p; foo(p); // foo(Plus) 함수 생성
	Minus m; foo(m); // foo(Minus) 함수 생성


}