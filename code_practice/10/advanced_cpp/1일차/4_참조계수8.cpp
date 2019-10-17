#include <iostream>
#include <atomic>   
using namespace std;

// 복사 금지는 자주 사용된다.
// 매크로화 한다.
#define WTF_MAKE_NONCOPYABLE(classname)				\
	classname(const classname&) = delete;			\
	classname& operator=(const classname&) = delete;


template<typename T> class RefCounted
{
	WTF_MAKE_NONCOPYABLE(RefCounted)

	// 함수 삭제 문법으로 복사 생성자와 대입연산자를 삭제 한다.
	// 복사 생성자와 대입연산자를 사용하면 컴파일 에러.
	//RefCounted(const RefCounted&) = delete;
	//RefCounted& operator=(const RefCounted&) = delete;

	mutable atomic<int> m_count = 0;
public:
	RefCounted() {}
	void ref()   const { m_count.fetch_add(1); }

	void deref() const
	{
		if (m_count.fetch_sub(1) == 1)
			delete static_cast<const T*>(this);
	}

protected:
	~RefCounted() {  }
};

class Truck : public RefCounted< Truck >
{
public:
	Truck() {}
	~Truck() { cout << "Truck 파괴" << endl; }

	Truck(const Truck& t) 
	{
		// 내 멤버만 복사.. 기반 클래스의 참조개수를 복사하거나
		// 기반 클래스의 복사 생성자를 호출하지는 말자.
		// 컴파일러가 만들어 주는 버전은 기반 클래스 복사생성자
		// 호출
	}
};


int main()
{
	Truck* p1 = new Truck; 	p1->ref();
	Truck* p2 = p1;         p2->ref();

	Truck* p3 = new Truck(*p1); // !!!!
	p3->ref();

	p1->deref();
	p2->deref();
}

