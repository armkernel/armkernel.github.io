// header file은 아래 header file만 있으면 됩니다.
#include <gtest/gtest.h>
#include <cstdio>


// test함수를 만드는 방법
TEST(FirstTest, foo) {
  printf("FirstTest.foo\n");
}

// main 함수가 필요하다
//  ==> 약속된 형식이 있다.

// 아래 부분에서 추가적으로 수행할 작업이 없다면, 미리 제공된 main을
// 라이브러리에 포함해서 사용하는 것이 좋다.
#if 0
int main( int argc, char** argv )
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
#endif
