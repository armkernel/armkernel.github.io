#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename T>
enable_if_t<is_same_v<decay_t<typename T::iterator_category>, random_access_iterator_tag> >
xadvance(T& p, int n)
{
	cout << "random �϶�" << endl;
	p = p + n;
}
  
template<typename T>
enable_if_t<! is_same_v<decay_t<typename T::iterator_category>, random_access_iterator_tag> >
xadvance(T& p, int n)
{
	cout << "random �ƴҶ�" << endl;
	while (n--) ++p;
}



int main()
{
	list<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	auto p = v.begin();

	xadvance(p, 5);

	cout << *p << endl;
}

