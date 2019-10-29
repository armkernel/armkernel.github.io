#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Terminal
{
public:
  void Connect() {}
  void DisConnect() {}

  void Login(const std::string& id, const std::string& passwd) {}
  void Logout() {}

  bool IsLogin() { return true; }
};

////////////////////
//

#include <gtest/gtest.h>

// 테스트를 구성하는 일반적인 방법
// => 클래스 별 테스트 케이스 클래스 (Testcase class per class)
//  : 하나의 SUT클래스에 대한 테스트 함수를 하나의 테스트 케이스 클래스 안에 전부 집어넣는다.
// 
// 생성이 느리면? 파괴가 느리면?
// 발생하는 문제가 있음 => 테스트 케이스가 많아지면 많아질수록 답이 없어짐.
// Slow test라는 문제가 존재한다.
//  : 테스트가 너무 느려서, 개발자들이 SUT가 변경되어도 매번 테스트를 실행하지 않는다.
//  (테스트를 수행하는 개발자의 생산성을 떨어뜨린다...)
//
//  해결 방법
//  Suite Fixture 를 사용하면 어느정도 해결이 가능하다.
//
// TestSuite.Setup() - static
//
// TestSuite ts = TerminalTest()
// ts.Setup()
// ts.Login()
// ts.TearDown()
//
// TestSuite.TearDown(); // terminal test안에서 한번만 하려면..
// - static
//
// 설치와 해체가 느릴 경우 사용해라.
//
// Suite Fixture 주의할점  (공유 픽스쳐의 전략)
// => fresh Suite class 전략 
//    => 매번 생성함. 신선하게 할려고 ... 공유 로 변경됨.
// => 이전 텍스쳐가 픽스쳐를 망가트릴 경우..
// 이후 테스트의 신뢰성의 문제가 된다. B가 A때문에 망가졌는데.. 실행이 안됨.
//
// 일반적인 경우에는 Suite Fixture를 사용하지 않는 경우가 있다. 
// 공유 픽스쳐의 전략을 사용해라.
// 
class TerminalTest : public ::testing::Test {
protected: 
  static Terminal* term;

  static void SetUpTestCase() {
    printf("SetUpTestCase()\n");
    term->Connect();
    term->Login("test_id", "test_password");
  }

  static void TearDownTestCase() {
    printf("TearDownTestCase()\n");
    term->DisConnect();
  }

  virtual void SetUp() override {
    printf("SetUp()\n");
  }

  virtual void TearDown() override {
    printf("TearDown()\n");
  }
};

// 정적 멤버 변수 외부정의 - 소스파일
Terminal* TerminalTest::term = nullptr;


TEST_F(TerminalTest, Login)
{
  // 내가 만든 SUT이기 때문에 사용법은 나만 안다.
  // act 단계

  ASSERT_TRUE(term->IsLogin()) << "로그인 하였을 때";

}

TEST_F(TerminalTest, Logout)
{

  term->Login("test_id", "test_password");
  term->Logout();

  ASSERT_FALSE(term->IsLogin()) << "로그아웃 하였을 때";

}



#if 0
class TerminalTest : public ::testing::Test {
protected: 
  Terminal* term;
  virtual void SetUp() override {
    term->Connect();
    term->Login("test_id", "test_password");
  }

  virtual void TearDown() override {
    term->DisConnect();
  }
};

TEST_F(TerminalTest, Login)
{
  // 내가 만든 SUT이기 때문에 사용법은 나만 안다.
  // act 단계

  ASSERT_TRUE(term->IsLogin()) << "로그인 하였을 때";

}

TEST_F(TerminalTest, Logout)
{

  term->Login("test_id", "test_password");
  term->Logout();

  ASSERT_FALSE(term->IsLogin()) << "로그아웃 하였을 때";

}
#endif
