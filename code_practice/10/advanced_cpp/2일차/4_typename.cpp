// 4_typename

class AAA
{
public:
	typedef int DWORD;
	static int value;
};
int AAA::value = 0;

template<typename T> void foo(T t)
{
	// 아래 한줄 해석해 보세요
	AAA::DWORD n; // int n   ok

	//T::DWORD n2; // error DWORD 가 static 멤버 변수인지 typedef인지
				// 알수 없기 때문에 error

	// C++ 규칙
	// T::이름  => 무조건 static 변수로 해석
	// typename T::이름  => "이름" 을 static 변수가 아닌 타입으로 
	//					   해석해 달라.
	int n2 = T::value; // ok

	typename T::DWORD n3; // typename이 반드시 필요 합니다.
}


int main()
{
	AAA a;
	foo(a);
}