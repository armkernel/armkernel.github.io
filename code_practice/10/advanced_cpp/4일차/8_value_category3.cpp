#include <iostream>
#include <type_traits>
using namespace std;


class Point
{
public:
	int x, y;
};


#define CHECK_VALUE_CATEGORY(...)									   \
	if (is_lvalue_reference< decltype(( __VA_ARGS__ )) >::value)	   \
		cout << "lvalue" << endl;									   \
	else if (is_rvalue_reference< decltype(( __VA_ARGS__ )) >::value ) \
		cout << "rvalue(xvalue)" << endl;                             \
	else                                                              \
		cout << "rvalue(prvalue)" << endl;


int main()
{
	CHECK_VALUE_CATEGORY(10);  // prvalue

	Point pt;
	CHECK_VALUE_CATEGORY(pt);  // lvalue
	
	CHECK_VALUE_CATEGORY(move(pt)); // xvalue
	
	CHECK_VALUE_CATEGORY(Point());  // prvalue 

	CHECK_VALUE_CATEGORY(Point().x); // xvalue 

	//Point().x = 10; //error
}


