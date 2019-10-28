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

// 3. 암묵적 설치. (Implicit Setup)
//   코드를 작성하지 않아도 자동적으로 설치되는 것들이 있다.
//   : xUnit Test Framework이 제공하는 하는 기능
//   => 여러 테스트에서 같은 테스트 픽스쳐를 Setup 함수에서 생성한다.
//
//   장점: 테스트 코드 중복을 제거하고, 꼭 필요하지 않은 상호작용 코드를 캡슐화 할 수 있다.
//   단점: 테스트 함수 안에서 감추어짐으로 테스트 함수 밖에서 확인해야한다. 코드 가독성이 떨어짐.
#include <gtest/gtest.h>

class CalculatorTest : public ::testing::Test {
public:
  CalculatorTest() { printf("Calculator() \n"); }
  ~CalculatorTest() { printf(" ~Calculator() \n"); }
protected:
  Calculator* calc;
  virtual void SetUp() override {
    // 어느시점에 호출되는지에 대한 걸 로깅해봄
    calc = new Calculator;
    printf("Setup()\n");
  }

  virtual void TearDown() override {
    // 암묵적 해체
    // Implicit Tear Donw function
    printf("TearDown() \n");
    delete calc;  
  }
};

// xUnit Test pattern에서 텍스트를 구성하는 방법
// 4단계 test pattern
// 1 단계. Arrange => text fixture를 설치 하거나 실제 결과를 관찰하기 위해 필요한 것들을 넣는 작업
// 2 단계. SUT와 상호작용한다.
// 3 단계. 기대 결과를 단언한다.
// 4 단계. 테스트 픽스쳐를 해체해서, 테스트 시작 이전 상태로 돌려 놓는다. (중요. 신선한 픽스쳐 유지 하기 위해서는 중요하다)


TEST_F(CalculatorTest, AddTest)
{
  // Arrange
  printf("AddTest1 \n");
  //Calculator* calc = new Calculator;

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
// ---------------
// xUnit Test Framework가 테스트를 수행하는 흐름.
// TestSuite ts = CalculatorTest();
// ts.SetUp();
// ts.AddTest();
// ts.TearDown(); 
// 암묵적으로 자기 자신의 원래 상태로 원복.
//
// 객체를 매번 생성한다. 한번만해도 상관없는데..
// 그 이유가 뭘까?
// 1. 가독성
// 2. 유지보수성
// 3. 신뢰성
//
// 신뢰성.. 반복적으로 수행해도 동일한 결과가 나와야한다. 신뢰성이 떨어지면 안돼. 테스트 자체에 있어서 신뢰성이 중요하게 하려면 각각의 테스 자체가 자기만의 독립적인 환경이 될 필요가 있다. 
//  => 신선한 픽스쳐 전략
//  => 모든 텍스쳐는 새로운 testSuite 객체에서 수행된다.
//
//
// TestSuite ts = CalculatorTest();
// ts.SetUp();
// ts.AddTest2();
//
// TestSuite ts = CalculatorTest();
// ts.SetUp();
// ts.Display_AddingTwoPlusTwo_ReturnsFour();

TEST_F(CalculatorTest, AddTest2)
{
  // Arrange
  
  printf("AddTest2 \n");
  //Calculator* calc = new Calculator;

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

  printf("AddTest3 \n");
  //Calculator* calc = new Calculator;

  //Act
  calc->Enter(2);
  calc->pressPlus();
  calc->Enter(2);
  calc->pressEquals();

  ASSERT_EQ(calc->Display(), 4) << "2+2 했을 때";

}
