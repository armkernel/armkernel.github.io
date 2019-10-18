#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <chrono> // s 사용
using namespace std;
using namespace std::chrono;

// github.com/asop-mirror
// platform_system_core
//
// libutils/include/utils/Thread.h 열어서 holdME 찾아보삼.
// libutils/Threads.cpp


// this를 가지고 shared pointer를 공유하게 해달라
class ConnectDB : public enable_shared_from_this<ConnectDB>
{
  // thread를 사용하는 클래스가 있다면,
  // 자신의 수명을 thread가 종료될 때 까지 유지해야한다.
  // 자신을 가리키는 스마트 포인터가 있어야 한다.
  shared_ptr<ConnectDB> holdMe; 
public:
  // 문제점 1. this는 raw pointer이므로 관리객체가 따로 생성됨. 
  //           RAII 위배 됨.
  // 문제점 2. 아직 thread가 생성되기 전으로 참조계수가 증가되면 안된다.
  /*
  ConnectDB() : holdMe(this)
  {
  }
  */
  ~ConnectDB() { cout << "~파괴" << endl; }

  void start()
  {
    // thread에 할일을 넣어주면 돼 규약이 적다.
    // holdMe = this; // compile 안되고, 되더라도 새로운 관리객체 생성

    holdMe = shared_from_this(); // 외부에서 만들었던 관리객체를 공유한다.

    thread t(&ConnectDB::Main, this);
    t.detach(); // linux join => 기다림, detach -> 안기다림.
  }
  virtual void Main()
  {
    shared_ptr<ConnectDB> sp(holdMe);
    holdMe.reset();

    this_thread::sleep_for(3s);

    cout << "DB 접속" << endl;
    // exception이 발생했을 때, 지역 변수는 안전하게 파괴된다.
    // 소멸자를 부르는 건 보장한다.


    // 멤버 데이타 사용자
    // 이것도 안좋음.. 가다가 에러 날 수도 있다.
    // holdMe.reset(); // 이렇게 하면 위쪽에서 예외 발생시
    //                 // 수행 될 수 없다.
    // thread가 끝나면 딱 종료됨.
  }
};

int main()
{
  {
    shared_ptr<ConnectDB> p(new ConnectDB);
    // 외부에 관리객체가 있다는 하에 실행됨.
    p->start();
    // 주 thread 벗어 날 때, 지워버림.
  }

  getchar();
}
