// 6_함수객체4
//
       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }
inline int Sub(int a, int b) { return a - b; }

// 1. 인라인 함수는 컴파일 시간에 이루어지는 문법이다.
// 2. 인라인 함수라도 함수 포인터에 담아서 호출하면 치환될 수 있다.

// add, sub 둘다 보낼 수 있다.
// add, sub는 다른 함수지만 같은 타입이다.
// 전달 받는 같은 타입.
// int를 반환하고 파라메타로 int를 두개 가지고 있는 함수는 모두 
// 아래의 함수로 귀결됨
void foo(int(*f)(int, int))
{
  int n = f(1,2);
}

int main()
{
  Add1(1, 2); // 호출
  Add2(1, 2); // 치환.. inline (빠르다.)

  int(*f)(int, int) = &Add2;


  // if (사용자 입력 == 1) f = &Add1;
  //

  foo(Add2); // 분명히 inline 함수를 부름. 
             // foo(Add1)도 보낼 수 있음
}
