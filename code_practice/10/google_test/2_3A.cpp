// 단위 테스트를 구성하는 방법.
//
// 테스트 대상 코드 (시스템)
//  => CUT( Code Under Test ) , SUT(System Under Test)
//
//
class Calculator {
public:
  void Enter(double value) {}
  void pressPlus() {}
  void pressMinus() {}
  void pressEquals() {}
  
  double Display() { return 0; }
};

// -----------
//
// test code영역

#include <gtest/gtest.h>
// #include "Calculator.h" 별도의 헤더파일이 필요함

// Test 메크로는 두개의 인자를 받음
// 1. TestCaseName , TestName
//
//
// TestCaseName / TestSuite 둘다 집합의 의미를가지고 있음
// TestSuite => 동일한 픽스쳐를 가지는 테스트의 집합
// 약간 느낌이 다르다.
//
// -   Test1
// -  Test2
// ... 하나의 그룹
//
// TEST(SUT의 이름 접미에 Test를 붙이는 것이 많이 사용됨.)

// 단위 테스트는 3A의 구성방법을 사용하는 것이 권장됩니다.
// 1. Arrange - 객체를 생성 필요한 경우 적절하게 설정하고 준비하는 단계
//  => Given
// 2. Act - 실제 객체에 작용을 가한다.
//  => When
// 3. Assert - 기대하는 바를 단언한다.
//  => Then

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
    // macro 
    // 명시적인 실패에 대해 보여주는 메크로 
    // 실패 가능성이 있는 함수
    // 단언 함수 (메크로) 를 사용할 때, 반드시 실패 메세지를 써주는 것이 좋다.
    // 결과를 보고도 에러 파악 가능 (즉, 코드를 보지 않아도 에러를 파악할 수 있어야한다. 중요하다)
    FAIL() << "2+2 했을 때";
  }
}


// method의 이름을 가지고만 어떤 식으로 동작하는지 알 수 없다.
//
// 테스트의 품질을 평가할 때, 중요한 지표 
//
// 테스트 코드의 품질
// 1. 가독성 => 테스트가 실패했을 때, 코드 안보고 알 수 있어야 하며, 코드를 들여다 봤을 때, 알 수있어야함.
// 2. 유지보수성
// 3. 신뢰성
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
  // 테스트 함수 안에서는 절대 제어구문을 사용하면 안된다.
  // 테스트 코드를 검증할 수 있는 테스트 코드는 존재하지 않는다.
  //  : 테스트 프레임 워크는 단언 메크로(함수)를 제공한다.
  ASSERT_EQ(calc->Display(), 4) << "2+2 했을 때";
  // 주의 해야하는 점. 쓰는 순서가 중요하다.
  // ASSERT_EQ/NE 사용할 때 주의할 점
  // 인자의 순서를 지키는 것이 중요
  // ASSERT_EQ(기대값, 실제값) 
  // 함수 사용할 경우 위와 같이 사용해야한다. 만약 잘못적어서 에러나면 찾기 힘듬
# if 0
  if (calc->Display() != 4) {
    FAIL() << "2+2 했을 때";
  }
# endif

}

i

// 테스트 코드를 보지 않아도, 테스트의 시나리오를 알 수 있도록 만드는 것이 좋다.
// e.g.) 테스트대상함수_시나리오_기대값
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

// 이름 자체가 정형화 되어져 있어야함
// 테스트의 목적과 종류에 따라 함수이름에 정형화 되어있어야함
