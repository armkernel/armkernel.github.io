// trival1
//

#include <iostream>

using namespace std;

class Sample
{
  int n;
public:

};

// Trivial : 하는 일이 없다.
// trival 조건
// 1. 가상함수 없고
// 2. 객체형 멤버 없고, 객체형 멤버의 생성자가 trivial 하고
// 3. 기반 클래스가 없고, 기반 클래스의 생성자가 trivial하고
// 4. 사용자가 만든 생성자가 없다면,
//
// " 생성자는 trivial 하다."
