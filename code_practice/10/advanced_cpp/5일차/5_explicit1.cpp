// 5_explicit1

class Vector
{
public:
	// explicit  : 직접 초기화만 가능하고 복사 초기화는 사용할수 없다
	explicit Vector(int sz) {}
};
// call by value 로 인자 전달 : copy initilization 사용
void foo(Vector v) {}  // Vector v = 10

int main()
{
	Vector v1(10);  // ok. direct initialization
	Vector v2 = 10; // ok  copy initialization  ( = 로 초기화)	
					// explicit 라면 error

	foo(10);	// explicit 라면 error


	goo(new int, hoo() ); // error

	shared_ptr<int> sp = new int; // error
	shared_ptr<int> sp(new int); // ok.
}

void goo(shared_ptr<int> sp, int n) {}
