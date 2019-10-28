// 4_GoogleTest 제공하는 기본 기능 


#include <gtest/gtest.h>

// 1. 단언함수, 단언메크로 
// 1. ASSERT_
//  EQ(==), NE(!=), LT(<), GT(>), LE(<=), GE(>=)
//  NULL, TRUE, FALSE
// 단언문 사용 시, 주의 사항 
TEST(GoogleTest, Sample1) {
  int expected = 42;

  // Act
  int actual1 = 42;
  int actual2 = 42;

  // Assert
  ASSERT_EQ(expected, actual1) << "Reason 1";
  ASSERT_EQ(expected, actual2) << "Reason 2";

  // 단언 메크로가 실패하는 순간.. 뒷 부분에 코드가 나오지 않음. 즉, 실행되지 않는다.
  // => 단언문이 실패하면, 이후의 코드는 수행되지 않습니다.
  //    하나의 테스트 함수 안에 많은 단언문이 존재하면, [죽은 단언문]의 문제가 발생할 수 있다.
  // => 테스트 함수 안에서ㅡ 최소한의 단언문을 사용하는 것이 좋다.
  // => 테스트 함수가 많아지는 문제가 발생함.
  //  => 논쟁의 소지가 있다. 여러개의 단언문을 쓰는 것에 대해서는 허용한다.
}

// EXPECT => 하나의 단언문이 실패하면, 뒤에 것들이 실행된다.
TEST(GoogleTest, Sample2) {
  int expected = 2;

  // Act
  int actual1 = 42;
  int actual2 = 42;

  // Assert
  EXPECT_EQ(expected, actual1) << "Reason 1";
  EXPECT_EQ(expected, actual2) << "Reason 2";
}


// 2. 문자열 비교
// C++에서는 문자열 표현 방법
//  const char*
//  std::string
//
//  차이점이 존재한다.
TEST(GoogleTest, Sample3) {
  std::string s1 = "hello";
  std::string s2 = "hello";

  EXPECT_EQ(s1,s2); // OK
  //성공하는 것이 맞음
  //s1 == s2 비교 
  //객체이기 때문에 연산자 오버로딩 때문에 문자열이 비교가 됨.

  const char* s3 = "hello";
  const char* s4 = "hello";

  EXPECT_EQ(s3,s4); // FAIL
  // 주소이기 때문에.. 우리가 상수였을 경우 동일한 주소를 가리킴. 만약 다른 경우 즉,s1.c_str() 이렇게 뽑으면 포인터의 주소가 다르다. 라는 식으로 출력이 될 수도 있다. 주소이기 때문에 별도의 단언함수가 제공됨.
  EXPECT_STREQ(s3,s4);
}


// 3.부동 소수점 타입에 대한 비교.
// 정밀성에 대한 오차가 발생함.
//
// ASSERT_DOUBLE_EQ, EXPECT_DOUBLE_EQ
// 오차범위가 얼마나 되야하는가?
//
TEST(GoogleTest, Sample4) {
  double a = 0.7;
  double b = 0.1 * 7;

  EXPECT_DOUBLE_EQ(a,b);
 // 오차범위를 직접 지정할 수 있다.
 // ASSERT_NEAR
}

// 4. 단위테스트 비활성화
// 단언문이 없다면.. code coverage가 올라 갈 수 있다.
// 따라서, coverage를 가지고 판단하면 안된다.
//

TEST(GoogleTest, DISABLED_Sample5)
{
  // 작성중 입니다.
  // => 단언문이 아무것도 없는 테스트는 성공합니다.

  FAIL() << " 작성 중입니다... \n";
  // code commit이 안되는 것들이 발생할 수 있다.
  // 막아야한다.
  // 주석으로 막으면, 이 테스트가 존재하는 것을 알 수 없다.
  // 잊혀진다..
  //
  // 테스트 결과에 상관없이, 비활성화 하는 기능을 xUnit Test Framework에서는 제공한다.
  // Disabled Test..
  // Test 케이스의 이름이 또는 테스트 함수의 이름이 DISABLED_로 시작하면 비활성화 됩니다.
  // --gtest-also-run-disabled-tests
  // --gtest_also_run_disabled_tests
}

TEST(DISABLED_GoogleTest, Sample6)
{
  // 작성중 입니다.
  // => 단언문이 아무것도 없는 테스트는 성공합니다.

  FAIL() << " 작성 중입니다... \n";
  // code commit이 안되는 것들이 발생할 수 있다.
  // 막아야한다.
  // 주석으로 막으면, 이 테스트가 존재하는 것을 알 수 없다.
  // 잊혀진다..
  //
  // 테스트 결과에 상관없이, 비활성화 하는 기능을 xUnit Test Framework에서는 제공한다.
  // Disabled Test.. fail이 뜸
}
