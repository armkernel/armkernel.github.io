#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
// 5���� �ݺ��� ������ Ÿ��ȭ �մϴ�. - empty class Ȱ��
// 5���� ������ Ÿ��ȭ �����Ƿ� �Լ� �����ε�� Ȱ��ɼ� �ִ�.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag       : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

// ���� �پ��� �ݺ��ڴ� ����� ����� �ݵ�� iterator_category��
// �����ϵ��� ����մϴ�.
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
// "Tag Dispatching" �̶�� �Ҹ��� ���.
// is_pointer<T>()   => true_type, false_type �Լ� ȣ��� ������ ����
template<typename T> 
void xadvance_imp(T& p, int n, random_access_iterator_tag)
{
	cout << "random �϶�" << endl;
	p = p + n;
}
template<typename T>
void xadvance_imp(T& p, int n, input_iterator_tag)
{
	cout << "random �ƴҶ�" << endl;
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

