#include <iostream>
#include <tuple>

using namespace std;

template<typename ... Types> void foo(Types ... args)
{
  // Types : int , double
  // ...의 위치가 가장 중요하다.

  pair<Types...> p1;
  // pair<int,double> p1;

  tuple<Types...> t1;
  // tuple<int,double> p1; 
  // tuple이 두개 보관 문제없어

  tuple<pair<Types...>> t2;
  //tuple<pair<int,double>> t2
  //pair 2개 필요.. tuple이 pair를 가진 형태
  // tuple<pair<Types>...> t3;
  // tuple<pair<int>, pair<double>> t3 
  // 문제는 tuple은 가능한데.. pair는 쌍으로 가지고 있어야함.
  // ...의 위치를 잘보자.

  tuple<pair<int, Types>...> t4;
  // tuple<pair<int,int>, pair<int,double>> t4;
  // 문제 없다.
  //


  // pair<tuple<Types...>> p2;
  // pair<tuple<int,double>> p2;
  // 안에 있는 tuple은 문제 없지만, pair가 문제.
  pair<tuple<Types>...>p3;
  // pair< tuple<int>, tuple<double>> p3;
  // tuple, pair 문제 없다.
}

int main()
{
  foo(1, 3.4);
}


