#include <iostream>
#include <type_traits>

using namespace std;

//enable_if 를 사용한 함수 템플릿
//조건을 만족하면 함수 템플릿 사용
//조건을 만족하지 못하면 SFINAE의 특징에 따라 후보자에서 제외
//다른 버전의 동일 이름 함수 사용 가능!
// 혹시 다른 함수도 없다면.. 에러나올 거야

// 에러를 나지 않게 하면서 안쓰도록 하는 것
template<typename T>
typename enable_if<is_integral<T>::value, T>::type

// 혹시 앞이 true라면, T로 가야해. 전체식은. 
gcd(T a, T b)
{
  cout << "T" << endl;
  return a;
}

double gcd(double a, double b) 
{ 
  cout << "double" << endl; 
  return 0; 
}

int main()
{
  gcd(3, 6);       // T 사용
  gcd(3.4, 2.8);   // double
  gcd(3.4f, 2.8f); // template사용함 -static_assert 때문에 에러.
}

