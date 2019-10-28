// C++17부터 지원

#include <iostream>

using namespace std;


template<typename ... Types>
int foo(Types ... args)
{
  int x[] = { args... }; // pack expansion.

  // C++17부터는 다르게.

  int n = (args + ...); // pack + ...; 
                      // fold expression
                      // 1 + (2 + (3+4))
                      // 반드시 괄호로 묶어야한다.
                      // compile가 내부적으로 하는 연산
  // cout << n << endl;

  return n;
}

int main()
{
  int n = foo(1, 2, 3, 4); // args : 1,2,3,4 

  cout << n << endl;
}

// fold expression 정리
// 1. 이항 연산자를 이용해서 parameter pack 내에 있는 요소에 연산을 수행하는 문법
// 2. parameter pack의 이름에서 ... 붙이지 않고 사용
//  - args... : pack expansion
//  - args + ...; : fold expression
// 4가지 형태
//  1. unary right fold : (args op ...) 
//    => E1 op (E2 op (E3 op E4));
//
//  2. unary left fold : (... op args)
//    => ((E1 op E2) op E3 ) op E4)
//
//  3. binary right fold (args op ... op init)
//    => E1 op (E2 op (E3 op (E4 op init)))
//    => e.g. // ( args + ... + 10 )
//            // 1 + (2 + (3 + (4 + 10)))
//
//  4. binary left fold (init op ... op args)
//    => (((init op E1) op E2) op E3) op E4
//    => e.g. (10 + ... + args)
//            (((10 + 1) + 2) + 3)+ 4
//
