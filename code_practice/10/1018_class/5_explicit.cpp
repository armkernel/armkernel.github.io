#include <iostream>

class Vector
{
public:
  // explicit : 직접 초기화만 가능하고 복사 초기화는 사용할 수 없다.
  explicit vector(int sz) {}
};

void foo(Vector v) {} // Vector v = 10.. 이렇게 받음
                      // 함수의 인자 전달은 결국 copy 초기화를 통해서 이루어짐.
                      //

int main()
{
  Vector v1(10); // ok. direct initialization
  Vector v2 = 10; // ok. copy initialization (= 로 초기화)

  foo(10); // explicit 라면 error

  goo(new int, hoo()); // 직접 초기화 할 수 있는 코드는 좋지 않다. 그래서 explicit을 넣어야함

  shared_ptr<int> sp = new int; // error

  shared_ptr<int>sp(new int);
}

void goo(shared_ptr<int> sp, int n) {}
