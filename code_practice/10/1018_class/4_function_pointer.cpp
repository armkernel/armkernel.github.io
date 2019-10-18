#include <iostream>

using namespace std;

class Shape
{
  public:
    virtual void Draw() { cout << " shape" << endl; }
    void foo() { cout << "foo" << endl; }
};

class Rect : public Shape
{
public:
    virtual void Draw() { cout << " rect" << endl; }
};

int main()
{
  // void (Shape::*f1)() = &Shape::foo;
  void (Shape::*f2)();

  f2 = &Rect::Draw; // f2에는 뭐가 있을까요?
                    // 함수 주소가 아닌 가상함수 테이블에 대한 index정보
                    // 진짜 함수면 함수의 주소
                    // 가상함수면 가상함수 테이블 index정보

  // 가상함수도 함수에 담아서 전달하면 다형성화 된다. 
  // 순수 가상함수도 주소를 담을 수 있다.-> 주소가 아니라 index정보를 줌

  Rect r;
  (r.*f2)(); // 정상적으로 동작하게 하려면 rect를 불러야함.
  (((shape&)r).*f2)();

}
