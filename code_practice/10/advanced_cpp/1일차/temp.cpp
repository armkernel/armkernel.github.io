#include <iostream>
#include <type_traits>
using namespace std;

class Test
{
public:
//	~Test() {}
//	~Test() = default;
};
int main()
{
	cout << is_trivially_destructible_v<Test> << endl;
}