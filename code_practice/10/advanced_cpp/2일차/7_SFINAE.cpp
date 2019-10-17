// 7_SFINAE - 215page
#include <iostream>
using namespace std;
//template<typename T>
//void foo(T a)      { cout << "T" << endl; }
//void foo(int a)    { cout << "int"    << endl; }
//void foo(double a) { cout << "double" << endl; }
//void foo(char a)   { cout << "char"   << endl; }
//void foo(short a)  { cout << "short"  << endl; }
void foo(...)      { cout << "..."    << endl; }

int main()
{
	foo(10); // 결과 예측해 보세요.
			// 1. int
			// 2. T   => template 으로 int 버전함수 생성
			// 3. error. int 는 char, short, double로 모두 변환가능
			//	   어떤 함수인지 알수 없다.
			// 4. ...
}

