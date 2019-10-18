#include <iostream>
#include <memory>

using namespace std;

class Point
{
  public:
    Point() { cout << " Point() " << endl; }
    ~Point() { cout << " ~Point() " << endl; }
};

void foo(void *p) { cout << "foo" << endl; free(p); }
// 해당 타입을 받는 포인터를 만들어야함.

int main()
{
  // 삭제자 변경
  shared_ptr<int> p1(new int);            // p1 소멸자에서 delete
  shared_ptr<void> p2(malloc(100), foo);  // 소멸자에서 foo 호출 
  shared_ptr<void> p3(malloc(100), free); // 인자 하나니까.
  shared_ptr<void> p4(malloc(100), [](void* p) { free(p); });

  // 배열 모양의 할당
  // 이렇게 만 적으면 버그..
  // shared_ptr<int> p5(new int[10]); // delete[] 필요
  shared_ptr<int> p5(new int[10], [](int *p) { delete[] p; }); // delete[] 필요
  // 생성자에서는 두번째 인자인 소멸자를 사용하지 않는다.
  // 참조 계수만 관리하는 게 아니다.
  // 관리 객체가 있다.
  // ----------------------
  // | *ref               |
  // | deconstructor 주소 |
  // ----------------------
  
  // 위의 함수는 많이 쓰는데 lambda쓰기에는 귀찮다.
  // default_delete<int> : delete
  // default_delete<int[]> : delete[]

  shared_ptr<int> p7(new int[10], default_delete<int[]>());
  // 그래도 이렇게 적는게 귀찮다.
  // |
  // v
  // shared_ptr<int[]> p8(new int[10]); // C++17에서 들어옴.
  // 공식적으로는 C++17 에서 부터 지원
  // vector 써라
  //

  shared_ptr<Point[]> p9(new Point[3]);

  //3_shared_ptr2.cpp:49:23: error: no matching constructor for initialization of 'shared_ptr<Point []>'
  // shared_ptr<Point[]> p9(new Point[3]);
  //

  // file 관리 객체.
  shared_ptr<FILE> sp1 (fopen("a.txt", "wt"), fclose);


 }
