#include <string>

// 1. 테스트 대역은 무조건 적용할 수 없다.
//  => 제품 코드가 테스트 대역을 적용할 수 있는 형태의 설계어이야 한다.
// 2. SUT가 협력 객체를 이용할 때, 느슨한 결합의 형태로 사용해야한다.
//   => 강한 결합: SUT가 협력 객체를 이용할 때, 구체적인 타입에 의존하는 것
//   => 약한 결합 : SUT가 협력 객체를 이용할 떄, 추상클래스나 인터페이스를 기반으로 의존해야한다.
//                 SUT가 협력 객체를 직접 생성해야하는 것이 아니라, 외부에서 생성해서 전달 받아야한다. 
//                 : DI (Dependency Injection) => testability가 좋다. 코드 보다보면 생성해서 전달할 게 많다.. 그건 DI 기반 설계 
//                 1. 생성자 주입 - 협력 객체가 반드시 필요한 객체 일 때
//                 2. 메소드 주입 - 협력 객체가 필수적이지 않을 때

// 의존성 주입에 대한 문제점.
// 보일러 플레이트 문제점.
//  반드시 필요하지만.. 반복적으로 발생하는 코드
//  A-> B,C,D
//  A(new B(), new C(), new D());
//  => 의존성 주입 프레임 워크를 사용하면 좋다.
//   boost library.... 난이도가 높다. 대거..


struct IFileSystem {
  virtual ~IFileSystem() {}

  virtual bool IsValid(const std::string& filename) = 0;
};


class FileSystem : public IFileSystem{
public:
  virtual bool IsValid(const std::string& filename) override{
    // ext.. NFS..
    return true;
  }
};

// 기존 SUT의 코드를 테스트 대역 적용 가능할 수 있는 형태로 변경하는 작업
//  -> 틈새 만들기
//  -> 기존의 SUT 사용방식이 변경되지 않도록 하는 것이 좋다.

class Logger {
private:
  IFileSystem* fs;
public:

  Logger(IFileSystem* p = nullptr) : fs(p) 
  {
    if (fs == nullptr) {
      fs = new FileSystem;
    }
  }
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
    // IFileSystem* fs = new FileSystem; 직접 생성하는 것은 없어지고 외부에서 생성한 것을 받아서 사용할 것이다.
    return fs->IsValid(filename);
  }
};

// 결함 국소화 장점.
// 테스트 대상 코드에 의해 결정되어야한다.
// 결과가 테스트 하는 부분에서 결정될 수 있도록.. 도와주는 것. 테스트 대역


// ------------------
//
class StubFileSystem : public IFileSystem {
public:
  virtual bool IsValid(const std::string& filename) { return true; }
};


#include <gtest/gtest.h>

class LoggerTest : public ::testing::Test {

};

TEST_F(LoggerTest, IsValidFilename_NameShorterThan5Chars_ReturnsFalse) {
  StubFileSystem stub;
  Logger logger(&stub);
  std::string badFilename = "bad.log"; // 자기 설명적인 이름은 의도파악하는데 도움이 된다.

  bool actual = logger.isValidFilename(badFilename);

  ASSERT_FALSE(actual) << " 파일명이 다섯글자 미만일 때";
}


TEST_F(LoggerTest, IsValidFilename_NameShorterThan5Chars_ReturnsTrue) {
  StubFileSystem stub;
  Logger logger(&stub);
  std::string goodFilename = "gooood.log";

  ASSERT_TRUE(logger.isValidFilename(goodFilename)) << "good";
}

// 종류 4가지
// 1. Test stub
// 2. Fake Object
// 3. Test Spy
// 4. Mock Object






