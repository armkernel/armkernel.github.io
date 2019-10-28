// 1. 일반함수는 자신만의 타입이 없습니다!
//   signature가 동일하면 모두 같은 타입 입니다.
//
// 2. 함수 객체는 자신만의 타입이 있다.
//   signature가 동일하고 모든 함수 객체는 다른 타입이다.

struct Plus
{
  inline int operator()(int a, int b) { return a + b; }
};

struct Minus
{
  inline int operator()(int a, int b) { return a - b; }
};
// -----------------------------

// 아무리 인라인 치환하고 싶어도 치환 불가능
// void foo(Plus p)
//
// 인자로 다양한 정책(함수)를 보낼 수 있는데,
// 정책이 인라인 치환이 가능한 코드..
// 함수 객체 + 템플릿으로 만드는 기술
template<typename T> void foo(T p)
{
  // 정책을 바꿨는데.. 성능저하가 없다.

  // 함수 포인터로 받으면 치환이 불가능하지만,
  // 함수 객체로 받으면 치환 가능
  int n = p(1,2);
}

int main()
{
  Plus p; foo(p);  // foo (Plus);
  Minus m; foo(m); // foo (Sub);
}
