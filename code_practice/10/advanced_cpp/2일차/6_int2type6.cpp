
// 115 page 소스는 결국 아래 이야기 입니다.
// "Modern C++ Design" 책의 저자인 "안드레이 알렉산드레스큐" 가 처음
// 소개한 코드!(2000년경)
template<int N> struct int2type
{
	enum { value = N };
};
int main()
{
	foo(0);
	foo(1); // 0, 1은 같은 타입(int), foo(0), foo(1) 은 같은 함수 호출

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1); // t0, t1은 다른 타입. foo(t0), foo(t1) 은 다른 함수 호출
}
