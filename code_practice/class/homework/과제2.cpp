#include <iostream>
#include <type_traits>

using namespace std;


template<typename T>
double average(T& t) 
{
  int sz = 0;
  double sum = 0;
  if constexpr (is_array_v<T>){
    sz = sizeof(t) / sizeof(typename remove_all_extents<T>::type);    
  } 
  else 
  {
    sz = t.size();
  }

  for (int i = 0; i < sz; i++){
    sum += t[i];
  }

  return sum / sz;
}


#include <vector>
int main()
{
  int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
  vector<int> y = { 1,2,3,4,5,6,7,8,9,10 };
  cout << average(x) << endl;
  cout << average(y) << endl;
}
