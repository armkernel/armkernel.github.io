#include <iostream>
#include <type_traits>

using namespace std;


template<typename T>
void average(T t)
{
  cout <<"vector" << endl;
}

template<typename T>
void average(T* t) 
{
  cout << "int[]"<< sizeof(t) << endl;
  
  cout << __PRETTY_FUNCTION__ << endl;
}

/*
template<typename T>
// enable_if_t<is_array<T>::value, T> 
average(T t)
{
  cout << typeid(T).name() << endl;
}*/

#include <vector>
int main()
{
  int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
  vector<int> aa = { 1,2,3 };
  average(aa);
  average(a);
}
