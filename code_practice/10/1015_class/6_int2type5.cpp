#include <iostream>
#include <type_traits>
using namespace std;

/*
 * 35. int to type.
 * 
 * */



template<int N> struct int2type
{
  enum { value = N };
};

template <typename T> void printv(T v)
{

    printv_imp(v, int2type< is_pointer<T>::value>());
                  // int2type<0>
                  // 데이터 타입에 괄호 붙이면 임시객체 만들어달라.
                  // template을 객체화 
    // 1, 0인 primitive 값을 반환
    // 오버로딩은 타입이랑 갯수 가 달라야함.
}

// 변수 명 빼면 그냥 선언만 하는 거고 아래에서는 안쓸꺼야.
template<typename T> void printv_imp(T v, int2type<1>)
{
    cout << v << ":" << *v << endl;
}

template<typename T> void printv_imp(T v, int2type<0>)
{
    cout << v << endl;
}


int main()
{
  int n = 0;
  printv(n);
  printv(&n);
}
