#include <iostream>

using namespace std;

class Data
{};

class Test
{
  Data data;
  double value;
public:
 
  // 지금 단점.. 우리가 필요한 것 data type에 대해 두개가 필요함
  //            임의의 타입에 대해서는 필요 없다.

  void SetData(double d) 
  { 
    value = d; 
    cout << " double " << endl;
  }

  // T : Data& 라고 온다면.. 다르게 봄.
  // T : const.. 붙으면.. 
  //
  // decay<T>::type => T에서 const, volatile, reference 제거한 타입
  template<typename T> 
  typename enable_if<is_same<typename decay<T>::type, Data>::value>::type
  SetData(T&& d)
  {
    data = std::forward<T>(d); // 3
  }
  
};

int main()
{
  Data d;
  Test t;
  t.SetData(3.4f);
  t.SetData(move(d)); // 내 자원 필요 없으니 move가져가라.
}


