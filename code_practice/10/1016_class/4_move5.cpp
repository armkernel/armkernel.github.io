#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  //string s1 = "hello";
  const string s1 = "hello";
  //string s2 = s1;
  string s2 = std::move(s1);
  cout << s1 << endl;

  vector<int> v1(10,3); // 느리다.. 메모리 통째로 복사
  //vector<int> v2 = v1;
  vector<int> v2 = std::move(v1); // 빠르다. 포인터만 전달

  cout << v1.size() << endl;
}
