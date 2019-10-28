#include <iostream>
using namespace std;

// int2type : int형 상수를 독립된 타입으로 만드는 도구

// integral_constant : 모든 정수형 타입을 독립된 타입으로 만든느 도구
/*template<typename T, T N> struct integral_constant
{
  static constant T value = N;  
};
*/
/*
// ture, false : 참 거짓을 나타내는 값, 같은 타입
// ture_type, false_type : 참 거짓을 나타내는 타입, 다른 타입
// 표준이다.

typedef integral_constant<bool,true> true_type;
typedef integral_constant<bool,false> false_type;

// is_pointer 등의 traits는 아래와 같이 만든다.
// template 상속
template<typename T> struct is_pointer : false_type{};
template<typename T> struct is_pointer<T*> : true_type{};
#include <type_traits> // 이 안에 모든  타입에 대한 것들이 다 있다.

int main()
{
  integral_constant<int, 0> t0;
  integral_constant<int, 1> t1;
  integral_constant<short, 0> t2;

}

*/
#include <type_traits>


// 변수 명 빼면 그냥 선언만 하는 거고 아래에서는 안쓸꺼야.
template<typename T> void printv_imp(T v, true_type)
{
    cout << v << ":" << *v << endl;
}

template<typename T> void printv_imp(T v, false_type)
{
    cout << v << endl;
}

template <typename T> void printv(T v)
{

    printv_imp(v, is_pointer<T>());
                  // int2type<0>
                  // 데이터 타입에 괄호 붙이면 임시객체 만들어달라.
                  // template을 객체화 
    // 1, 0인 primitive 값을 반환
    // 오버로딩은 타입이랑 갯수 가 달라야함.
}

int main()
{
  int n = 0;
  printv(n);
  printv(&n);
}
