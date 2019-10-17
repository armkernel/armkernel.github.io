#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename T>
void xadvance(T& p, int n)
{
	// C++17  
	// g++ : -std=c++17
	// vc  : /std:c++17   ¶Ç´Â /std:c++latest
	if constexpr (is_same_v<decay_t<typename T::iterator_category>,
				  random_access_iterator_tag>  )
	{
		p = p + n;
	}
	else
	{
		while (n--) ++p;
	}	
}



int main()
{
	list<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	auto p = v.begin();

	xadvance(p, 5);

	cout << *p << endl;
}

