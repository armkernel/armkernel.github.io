#include <iostream>
#include <type_traits>
using namespace std;

// enable_if 를 사용한 함수 템플릿
// 조건을 만족하면 함수 템플릿 사용
// 조건을 만족하지 못하면 SFINAE 의 특징에 따라 후보에서 제외
// 다른 버전의 동일 이름 함수 사용 가능!

template<typename T>
typename enable_if< is_integral<T>::value, T>::type
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
	gcd(3, 6);			
	gcd(3.4, 2.8);		
	gcd(3.4f, 2.8f);	
}



