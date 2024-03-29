#include <iostream>

using namespace std;

class Animal
{
  int age;
};

class Dog : public Animal
{
  int color;
};


int main()
{
  Dog d;
  Dog* p1 = &d; // dog의 포인터를 잡는 건 문제없다.

  double* p2 = &d; // 전혀 다른 타입으로 포인팅한다면.. 그건 에러.

  Animal* p3 = &d; // 이번에는 전혀 남은 아니고 기반 클래스다. 과연 파생클래를 기반클래스의 포인터에 담을 수 있냐? 그건 허용된다.
  // C++ 뿐만아니라 다른 것도 가능함.
  // 메모리적으로 생각
  // 순서가.. Animal 포함하고 Dog정보가 담김
  // 그림으로 그려봐
  //
  // 기반 클래스 따라가면 기반클래스가 있음. 메모리 문제상 문제가 없다. 따라서, 허용해줌.
  // 기반클래스는 파생클래스를 가리킬 수 있다.
  //
  //
  //왜 중요한가>?
  //
  // 윈도우 탐색기를 생각해보자.
  // 탐색기를 객체지향으로 설계하라
  // Folder, File 클래스를 만들어야함. Folder라는 클래스는 다시 다양한 File을 가질 수 있음
  // Folder는 File을 vector가져야함. File만 가지고 있는게 아니라 Folder안에는 Folder를 가짐.
  // 이 친구는 Folder를 가져야함. void*를 쓸 수있지만.. 모든 타입을 가지게 됨.
  //
  // 폴더와 파일의 공통의 기반클래스를 만들어야함. 기반 클래스는 모든 파생클래스를 가리킬 수 있다.
  //
  // 폴더에 파일 뿐만아니라 폴더도 보관 하기 위해서는 기반클래스로 뽑아야함.
  //
  //
  // 하나만 더 생각해보자.
  // 파워 포인터 도형을 생각해보자. 
  // 사각형과 도형이 있음
  // Rect.. Circle.. 동시에 선택해서 그룹으로 만들 수 있음 Group.. 
  // Group 내부적으로 vector<Rect*>를 가지면 Rect를 보관할 수 있음.. 둘 다 가능하게 하려면.. 공통으로 뽑아야함.
  //
  //
  // 상속이 물려받을 때만 쓴다에 많이 쓰는 것이 아니라 .. 동족끼리 묶을 때 많이 사용!! 
  //
  // 작은 그룹이 큰그룹에 들어감. 
  // 또 뽑아야해.. 
  // 자료구조 모양에서 트리모양 비슷해짐.. 
  // => composite pattern이라고 칭함.

  // 다양한 구조를 묶어서 관리하고 싶다면.. 공통의 기반 클래스를 뽑아야해




}


