#include <iostream>

using namespace std;

void goo(int a, int b, int c)
{
  cout << a << ", " << b << ", " << c << endl;
}

int hoo(int a) { return -a; }

template<typename ... Types> void foo(Types ... args)
{
  // 가변인자 템플릿 안에서, args안에 들어있는 parameter pack을 풀어주기 위해서는 pack expansion 하면 돼.. "parameter..." 을 해주면 돼. 
  // (,)를 이용해서 pack안에 들어있는 arg들을 풀어 달라. 
  // int x[] = { args... }; // pack expansion
                      // {1, 2, 3};

  // paramter pack
  // pack expansion의 정확한 의미
  // "parameter pack을 사용하는 패턴"...
  //  => 패턴(e1), 패턴(e2), 패턴(e3)
  // int x[] = {(++args)...}; 
  // (++args) <- 하나의 패턴
  // {2,3,4}

  // int x[] = { hoo(args...) }; // hoo(1,2,3)
                              // 우리의 hoo는 인자 하나만 받음 -> error.
                              //
  int x[] = { hoo(args)... }; // { hoo(1), hoo(2) , hoo(3) };
  
  // => { -1, -2, -3 };

  //goo(args...); // goo (1,2,3)
  //goo(hoo(args...)); // goo(hoo(1,2,3)); // hoo가 인자가 하나만 받기 때문에 에러
  goo(hoo(args)...); // goo(hoo(1), hoo(2), hoo(3));


  // pack을 사용하는 pattern을 만들면. 그 팩을 기준으로 ,로 나뉨



  // for each문
  for (auto n : x)
    cout << n << endl;
}

int main()
{
  foo(1,2,3); // Types : int, int, int
              // args : 1, 2, 3
}
