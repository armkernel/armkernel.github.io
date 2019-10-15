#include <iostream>
#include <type_traits>

using namespace std;

/*
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
    // 조사해서 다시 분배
}
*/

template<typename T>
typename enable_if<is_pointer<T>::value>::type
printv(T v)
{
    cout << v << ":" << *v << endl;
}

template<typename T>
typename enable_if<!is_pointer<T>::value>::type
printv(T v)
{
    cout << v << endl;
}

// 함수가 3개가 아니라 2개로 해결됨

// 3. 함수 템플릿을 2개 만들고 enable_if로 조건에 따라 사용하도록
// template<typename T>
// typename enable_if<is_pointer<T>::value>::type
// foo (T a)
// {
// }

// typename enable_if<!is_pointer<T>::value>::type
// foo (T a)
// {
// }
//
// 기술이 나온 순서
// 2번의 true_type/false_type
// 3번의 enable_if
// 1번의 if constexpr
//
// github.com/aosp-mirror
// platform_system_core 2번째
// libutils/include/utils/typehelpers.h 안에 copy_type



int main()
{
  int n = 0;
  printv(n);
  printv(&n);
}
