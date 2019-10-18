// 7_unique_ptr
#include <iostream>
using namespace std;

template<typename T>
class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}
	~Ptr() { delete obj; }
	T* operator->() { return obj; }
	T& operator*() { return *obj; }

	// 복사와 대입을 금지한다.
	Ptr(const Ptr&) = delete;
	Ptr& operator=(const Ptr&) = delete;
};

int main()
{
	Ptr<int> p1 = new int;
	*p1 = 10;
	cout << *p1 << endl;

	//Ptr<int> p2 = p1;  // 복사 생성자.. 얕은복사 문제..

}