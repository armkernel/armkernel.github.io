// fake object 는 언제 사용하는가?
//  -> 1. 목적. 특수한 사항을 시뮬레이션 하기 위해서 사용
//
//  2. 아직 준비되지 않는 의존 객체로 인해 테스트 안된 요구사항이 있을 때.

#include <ostream>
#include <string>

// DO, DTO, DAO <- Data 중심의 클래스
class User {
  std::string name;
  int age;
public:
  User(const std::string& n, int a) : name(n) , age(a) {}

  std::string GetName() const { return name; }
  int GetAge() const { return age; }

};

struct IDatabase {
  // user 객체를 저장하고 불러오는 역할을 함.
  virtual ~IDatabase() {}

  virtual void SaveUser(const std::string& name, User* user) = 0;
  virtual User* LoadUser(const std::string& name) = 0;
};

class UserManager {
  IDatabase* database;
public:
  UserManager(IDatabase* p) : database(p) {}

  void Save(User* u) {
    //...
    database -> SaveUser(u->GetName(), u);
    // ...
  }

  User* Load(const std::string& name) {
    //..
    database->LoadUser(name);
    //..
  }
};

// 내가 SUT를 만들려고 하는데 협력되는 객체가 만들어지지 않는경우 -> fake 를 사용함.
// ------------------
//
#include <gtest/gtest.h>

// Fake Object Pattern
//  -> 의존 객체를 사용할 수 없을 때, 해당 로직을 독립적으로 검증 가능하다.
//  -> 의존 객체가 너무 느려서 사용하기 어려울때.
//
//
#include <map>
class MemoryDatabase : public IDatabase {
  std::map<std::string, User*> data;
public:
  virtual void SaveUser(const std::string& name, User* user) override {
    data[name] = user;
  }

  virtual User* LoadUser(const std::string& name) override {
    return data[name];
  }
};


bool operator==(const User& lhs, const User& rhs) 
{
  return lhs.GetName() == rhs.GetName() && 
        lhs.GetAge() == rhs.GetAge();
}


bool operator!=(const User& lhs, const User& rhs) 
{
  return !(lhs==rhs);
}

// 객체의 출력방식을 재정의 하기 위해서는 아래와 같은 방법이 필요하다
std::ostream& operator<<(std::ostream& os, const User& user) {
  return os << user.GetName() << " ( " << user.GetAge() << " )" << std::endl; 
} 


class UserManagerTest : public ::testing::Test {};

TEST_F(UserManagerTest, SaveAndLoad) {
  MemoryDatabase fake;
  UserManager manager(&fake);

  std::string testName = "test_id";
  int testAge = 42;
  User expected(testName, testAge);

  manager.Save(&expected);
  User* actual = manager.Load(testName);

  // 사용자 정의 객체.. -> operator==를 만들어야함.
  ASSERT_EQ(expected, *actual);
}
