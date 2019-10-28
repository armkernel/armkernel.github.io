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

// libutils/include/utils/Thread.h ��� mHoldSelf ã�ƺ�����
// libutils/Threads.cpp  ���� threadLoop ã�� ������.



class ConnectDB : public enable_shared_from_this<ConnectDB>
{
	// �����带 ����ϴ� Ŭ������ �ִٸ�
	// �ڽ��� ������ �����尡 ����ɶ� ���� ���� �ؾ� �Ѵ�.
	// �ڽ��� ����Ű�� ����Ʈ�����Ͱ� �־�� �Ѵ�.
	shared_ptr<ConnectDB> holdMe;
public:
	// ������ 1. this �� raw pointer �̹Ƿ� ������ü�� ���� ������
	// ������ 2. �����ڿ����� �����尡 �����Ǳ� ���̴�.
	//			��������� ������ �ʿ� ����
	/*
	ConnectDB() : holdMe(this)
	{
	}
	*/
	void start()
	{
		//holdMe = this; // �����ϵ� �ȵǰ�, �Ǵ��� ���ο� ������ü����

		holdMe = shared_from_this(); // �ܺο��� �������
								// ������ü�� �����ϰ� ���ش�.

		thread t(&ConnectDB::Main, this);
		t.detach();
	}

	~ConnectDB() { cout << "~�ı�" << endl; }

	virtual void Main()
	{
	//	shared_ptr<ConnectDB> sp(holdMe);
	//	holdMe.reset();

		this_thread::sleep_for(3s);

		cout << "DB ����" << endl;	
		// ��� ����Ÿ �����

		//holdMe.reset(); // �̷��� �ϸ� ���ʿ��� ���� �߻���
						// ����ɼ� ����.
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

