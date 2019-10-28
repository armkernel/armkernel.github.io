// 단위 테스트를 구성하는 방법.
class Calculator {
public:
  void Enter(double value) {}
  void pressPlus() {}
  void pressMinus() {}
  void pressEquals() {}
  
  double Display() { return 0; }
  // Calculator(double n) {}
};


#include <gtest/gtest.h>

// Fixture
// 1. 정의: xUnit Test Pattern에서 SUT를 실행하기 위해서 준비해야하는 모든 것을 테스트 픽스쳐라고 한다.
// 2. 픽스쳐를 구성하는 모든 로직 부분을 '픽스쳐를 설치한다' 라고 합니다.
//

// 픽스쳐 설치 방법 3가지
// 1. inline 픽스쳐 설치
//  - 모든 픽스쳐 설치를 테스트 함수 안에서 수행한다.
//  - 아래의 코드 처럼.. 테스트 함수 안에다가 필요한 코드를 작성
//    - 장점 : 테스트 함수 하나만 봤을 때, 어떤식으로 설치 및 수행 검증을 알 수 있다. (함수 하나로 판단 가능)
//    - 단점 : 모든 테스트 함수 안에서 ' 코드 중복 '이 발생한다.
//    (테스트 함수안에서 암묵적으로 코드 중복은 당연한것이다? 아니다. 냄새..)
//
//    테스트 냄새
//      : 테스트 코드의 유지 보수를 떨어뜨리는 요소
//
// 2. 

#if 0
TEST(CalculatorTest, AddTest)
{
  // Arrange
  Calculator* calc = new Calculator;

  //Act
  calc->Enter(2);
  calc->pressPlus();
  calc->Enter(2);
  calc->pressEquals();

  // Assert
  if (calc->Display() != 4) {
    FAIL() << "2+2 했을 때";
  }
}


TEST(CalculatorTest, AddTest2)
{
  // Arrange
  Calculator* calc = new Calculator;

  //Act
  calc->Enter(2);
  calc->pressPlus();
  calc->Enter(2);
  calc->pressEquals();

  // Assert
  ASSERT_EQ(calc->Display(), 4) << "2+2 했을 때";
}

TEST(CalculatorTest, Display_AddingTwoPlusTwo_ReturnsFour)
{
  // Arrange
  Calculator* calc = new Calculator;

  //Act
  calc->Enter(2);
  calc->pressPlus();
  calc->Enter(2);
  calc->pressEquals();

  ASSERT_EQ(calc->Display(), 4) << "2+2 했을 때";

}
#endif

// 픽스쳐 설치 방법 2. 위임 설치
//  : 1. 동일한 픽스쳐를 가진 테스트 함수를 클래스로 묶는다.
//    2. 픽스쳐 설치에 관한 중복되는 코드를 함수로 제공한다.
//  Test suite 함수

// 1. 
class CalculatorTest : public ::testing::Test {
// private: //내부에서만 사용하는 경우..
  // private을 쓰면 안됨. 외부에서 호출 되지 않도록..
  // protected:로 해야됨.. 그래야 TEST_F의 함수안에서 접근이 가능
//private:
protected:
  // 테스트 유틸리티 함수
  //  => 생성 함수
  //  이렇게 하나로 묶으면 더 이득이 됨.
  //  복잡함을 감추고 있어서 이해하는데 도움이 됨
  //  이름을 별도의 함수에 위임하는 함수.
  Calculator* Create() {
    return new Calculator;
  }
};


// TEST -> TEST_F 
// 동일한 타입을 공유한다는 의미로 변경해야함. 주의.

TEST_F(CalculatorTest, AddTest)
{
  // Arrange
  Calculator* calc = Create();

  //Act
  calc->Enter(2);
  calc->pressPlus();
  calc->Enter(2);
  calc->pressEquals();

  // Assert
  if (calc->Display() != 4) {
    FAIL() << "2+2 했을 때";
  }
}


TEST_F(CalculatorTest, AddTest2)
{
  // Arrange
  Calculator* calc = Create();

  //Act
  calc->Enter(2);
  calc->pressPlus();
  calc->Enter(2);
  calc->pressEquals();

  // Assert
  ASSERT_EQ(calc->Display(), 4) << "2+2 했을 때";
}

TEST_F(CalculatorTest, Display_AddingTwoPlusTwo_ReturnsFour)
{
  // Arrange
  Calculator* calc = Create();

  //Act
  calc->Enter(2);
  calc->pressPlus();
  calc->Enter(2);
  calc->pressEquals();

  ASSERT_EQ(calc->Display(), 4) << "2+2 했을 때";

}
