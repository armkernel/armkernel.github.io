#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
// 5개의 반복자 종류를 타입화 합니다. - empty class 활용
// 5개의 개념을 타입화 했으므로 함수 오버로딩등에 활용될수 있다.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag       : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

// 이제 다양한 반복자는 만드는 사람은 반드시 iterator_category를
// 제공하도록 약속합니다.
template<typename T> class vector_iterator
{
public:
	typedef random_access_iterator_tag iterator_category;
};

template<typename T> class list_iterator
{
public:
	typedef bidirectional_iterator_tag iterator_category;
};
*/
// "Tag Dispatching" 이라고 불리는 기술.
// is_pointer<T>()   => true_type, false_type 함수 호출과 유사한 개념
template<typename T> 
void xadvance_imp(T& p, int n, random_access_iterator_tag)
{
	cout << "random 일때" << endl;
	p = p + n;
}
template<typename T>
void xadvance_imp(T& p, int n, input_iterator_tag)
{
	cout << "random 아닐때" << endl;
	while (n--) ++p;
}
template<typename T> void xadvance(T& p, int n)
{
	xadvance_imp(p, n, typename T::iterator_category());
}



int main()
{
	list<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	auto p = v.begin();

	xadvance(p, 5); 

	cout << *p << endl;
}

