
// C++ 에서는 new와 delete 연산을 재정의하는 것이 가능하다.
//  => 고유의 메모리 할당기를 사용할 수 있다. (tcmalloc, jemalloc) 
//  성능이 좋다. 테스트에서는 테스트로 인한 메모리 누수가 있는지 확인하는 용도로 사용할 수 있다.

#include <gtest/gtest.h>
// macro를 만듬

#ifdef LEAK_TEST
#define DECLARE_LEAK_TEST() \
public:\
  static int allocObjectCount;\
  void* operator new(size_t sz) {\
    ++allocObjectCount;\
    return malloc(sz);\
  }\
  \
  void operator delete(void* p, size_t) {\
    --allocObjectCount;                  \
    free(p);                             \
  }

#define IMPLEMENT_LEAK_TEST(classname) \
int classname::allocObjectCount = 0;
#else 
#define DECLARE_LEAK_TEST()
#define IMPLEMENT_LEAK_TEST(classname)
#endif

class Image
{
  DECLARE_LEAK_TEST()
};

IMPLEMENT_LEAK_TEST(Image);


class ImageTest : public ::testing::Test {
protected:
  int allocCount;

  virtual void SetUp() override {
#ifdef LEAK_TEST
    allocCount = Image::allocObjectCount;
#endif
  }

  virtual void TearDown() override {
#ifdef LEAK_TEST
    int diff = Image::allocObjectCount - allocCount;
    EXPECT_EQ(0,diff) << "Leaked - " << diff;
#endif
  }
};

void foo()
{
  Image* i1 = new Image;
}

TEST_F(ImageTest, LeakTest) {
  foo();
}

