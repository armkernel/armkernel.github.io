// 추상 클래스의 활용 예..
// interface 와 coupling
//
#include <iostream>
using namespace std;

class Camera
{
public:
  void take() { cout << " take picture " << endl; }
};

class HDCamera
{
public:
  void take() { cout << " HDtake picture " << endl; }
};


class People
{
public:
  void useCamera(Camera* p) { p -> take(); }
  void useCamera(HDCamera* p) { p -> take(); }
};

int main()
{
  People p;
  Camera c;
  // 사람이 있고 카메라를 가지고 카메라를 이용해 사진을 찍음.
  //
  // 세월이 지나.. 카메라가 새로나왔어.
  p.useCamera(&c);

  // HD 카메라가 생겨서 HD 카메라를 넘겨서 사진을 찍는다고 해보자.
  //
  HDCamera hc; // 카메라를 새로삼
  p.useCamera(&hc);
  // 사람은 항상 카메라만 사용.. 그래서 에러남. 그래서 HDCamera를 사용할 수 있는 함수가 필요하다.
  // 실행이 잘된다.
  // 문제없는거 아닌가?
  // HD 카메라가 원래는 없었다. 하지만 나중에 추가가 됨. 나중에 뭔가 도입이 됐을 경우 기존에 잘 돌고 있던 코드를 수정을 해야한다? 그럼 좋을까? 노노... 문제가 발생할 수 있어.
  //

}
