// 7_람다표현식

int main()
{
  // 람다 표현식 활용 1. STL 사용시 알고리즘 함수의 인자로 전달
  sort(x, x + 10, [](int a, int b) { return a < b; });


  // 활용 2. auto 변수에 담아서 함수 처럼 사용.

  // 반환값을 적고 싶다면 -> data type
  auto f = [](int a, int b) -> int { return a + b; };
    // class xxx{}; xxx(); 임시객체를 만들어줌.
    // 객체기 때문에 어떤 변수에 담아서 사용가능

  // 이제 f를 함수 처럼 사용하면 된다.
  int n = f(1,2);

  // 다음 중 에러를 모두 고르시오.
  auto f1 = [](int a, int b) { return a + b; }; // class xxx{}; xxx(); 임시객체를 값타입으로 변경 문제없다.
  auto& f1 = [](int a, int b) { return a + b; }; // error.
  auto&& f1 = [](int a, int b) { return a + b; }; // ok.

  decltype(f1) f4;    // error util c++17, ok c++20
  decltype(f1) f5(f1); // ok .. 복사 생성자 제공

}
