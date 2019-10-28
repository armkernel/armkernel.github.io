#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Object
{
public:
	Object() = default;
	Object(const Object& obj) { cout << "copy" << endl; }
	Object(Object&&) = default;
};

int main()
{
	Object o1;
	Object o2 = o1;
	Object o3 = move(o1);
}


