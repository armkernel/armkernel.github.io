#include <string>

class FileSystem{
public:
  bool IsValid(const std::string& filename) {
    // ext.. NFS..
    return true;
  }
};

class Logger {
public:
  // file.log
  //  1. 확장자를 제외한 파일의 이름은 반드시 5글자 이상이어야 한다.
  bool isValidFilename(const std::string& filename) {
    // ------ 테스트 대상코드
    size_t index = filename.find_last_of(".");
    std::string name = filename.substr(0, index);

    if (name.size() < 5)
      return false;
    // 
    // 2. 파일 시스템에서 생성 가능한 이름인지 확인한다.
    FileSystem* fs = new FileSystem;
    return fs->IsValid(filename);
  }
};

// 결함 국소화 장점.
// 테스트 대상 코드에 의해 결정되어야한다.
// 결과가 테스트 하는 부분에서 결정될 수 있도록.. 도와주는 것. 테스트 대역

#include <gtest/gtest.h>

class LoggerTest : public ::testing::Test {

};

TEST_F(LoggerTest, IsValidFilename_NameShorterThan5Chars_ReturnsFalse) {
  Logger logger;
  std::string badFilename = "bad.log"; // 자기 설명적인 이름은 의도파악하는데 도움이 된다.

  bool actual = logger.isValidFilename(badFilename);

  ASSERT_FALSE(actual) << " 파일명이 다섯글자 미만일 때";
}


TEST_F(LoggerTest, IsValidFilename_NameShorterThan5Chars_ReturnsTrue) {
  Logger logger;
  std::string goodFilename = "gooood.log";

  ASSERT_TRUE(logger.isValidFilename(goodFilename)) << "good";
}








