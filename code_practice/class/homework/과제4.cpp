
#include <iostream>

using namespace std;


template<typename T, typename ... Types> 
void cpp_print(T value, Types ... args)
{
  string str = value;
  
  int a = 0;
  size_t found = 0 ;

  while(found != std::string::npos)
  {
    found = str.find("%d",found+1);
    a++;
  }

  if( a != sizeof...(args) ) throw 1;
}


int main()
{
  printf("%d\n", 1, 2, 3); // 인자가 너무 많습니다.
  printf("%d%d\n", 1); // 인자가 부족 합니다.

  try {
    cpp_print("%d\n", 1, 2, 3); // 예외 발생
    cpp_print("%d%d\n", 1); // 예외 발생
    cpp_print("%d\n",1);    // 성공 예시
  } 
  catch (...)
  {
    cout << "예외 발생";
  }
  
}
