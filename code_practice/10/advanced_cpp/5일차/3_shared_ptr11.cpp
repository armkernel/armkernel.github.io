// 3_shared_ptr11
#include <iostream>
#include <memory>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

// github.com/aosp-mirror
// platform_system_core

// libutils/include/utils/Thread.h 열어서 mHoldSelf 찾아보세요
// libutils/Threads.cpp  에서 threadLoop 찾아 보세요.



class ConnectDB : public enable_shared_from_this<ConnectDB>
{
	// 스레드를 사용하는 클래스가 있다면
	// 자신의 수명을 스레드가 종료될때 까지 유지 해야 한다.
	// 자신을 가리키는 스마트포인터가 있어야 한다.
	shared_ptr<ConnectDB> holdMe;
public:
	// 문제점 1. this 는 raw pointer 이므로 관리객체가 따로 생성됨
	// 문제점 2. 생성자에서는 스레드가 생성되기 전이다.
	//			참조계수가 증가될 필요 없다
	/*
	ConnectDB() : holdMe(this)
	{
	}
	*/
	void start()
	{
		//holdMe = this; // 컴파일도 안되고, 되더라도 새로운 관리객체생성

		holdMe = shared_from_this(); // 외부에서 만들었던
								// 관리객체를 공유하게 해준다.

		thread t(&ConnectDB::Main, this);
		t.detach();
	}

	~ConnectDB() { cout << "~파괴" << endl; }

	virtual void Main()
	{
	//	shared_ptr<ConnectDB> sp(holdMe);
	//	holdMe.reset();

		this_thread::sleep_for(3s);

		cout << "DB 접속" << endl;	
		// 멤버 데이타 사용중

		//holdMe.reset(); // 이렇게 하면 위쪽에서 예외 발생시
						// 수행될수 없다.
	}
};


int main()
{
	{
		shared_ptr<ConnectDB> p(new ConnectDB);
		p->start();
	}

	getchar();
}

