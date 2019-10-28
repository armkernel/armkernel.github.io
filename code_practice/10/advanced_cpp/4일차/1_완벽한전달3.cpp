#include <iostream>
#include <type_traits>
using namespace std;

class Data {};

class Test
{
	Data data;
	double value;
public:
	void SetData(double d) 
	{
		value = d; 
		cout << "double" << endl;
	}

	// T : Data&
	// decay<T>::type => T에서 const, volatile, reference 를 제거한 타입
	template<typename T> 
	typename enable_if<is_same<typename decay<T>::type, Data>::value>::type 
	SetData(T&& d)
	{
		data = std::forward<T>(d); // 3
	}
};

int main()
{
	const Data d;
	Test t;
	t.SetData(3.4f);

	t.SetData(d);
	t.SetData(move(d));
}





