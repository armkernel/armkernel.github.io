#include <iostream>

using namespace std;

class Data
{
  
};

class Test
{
  Data data;
public:
  // setter 만들기
  // 방법1. 2개의 함수 제공하기. - 가장 좋은 방법
  // void SetData(const Data& d) { data = d; }
  // void SetData(Data&& d) { data = move(d); } // 50개가 있다면.. 다 만들어야함.

  // 방법2. forwarding reference 사용
  // T&& : Data& 와 Data&&의 함수를 자동 생성 (Data라고 가정)
  //      const Data&
  //
  //      함수의 갯수가 많아지는 단점이 있음
  template<typename T> void SetData(T&& d)
  {
    // 다음 중 맞는 것은?
    data = d; // 1 => 항상 복사
    // move: 인자를 항상 rvalue 캐스팅 
    data = std::move(d); // 2 const가 아니고 move 생성자가 있으면 항상 move => && 캐스팅 
    
    // 받은게 어떤건지.. 따라 cating이 달라짐. 즉, 상황에 따라 move가 불리고 copy가 불림.
    // forward: main 함수에서 rvalue를 보내면 rvalue 캐스팅
    //                        lvalue 보내면 lvalue 캐스팅
    data = std::forward<T>(d); // 3
  }
  
};

int main()
{
  Data d;
  Test t;
  t.SetData(d);
  // move를 안보내면.. -> d를 사용할 수 있다.
  t.SetData(move(d)); // 내 자원 필요 없으니 move가져가라.
                      // const 써두면 받을 수 없다.
}


