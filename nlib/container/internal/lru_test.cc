#include "nlib/container/lru.h"

#include "gtest/gtest.h"

namespace nlib {

namespace container_internal {

namespace {

TEST(LRUTest, SimpleTest) {
  LRU<int> testee;

  testee.Insert(1);  // 1
  testee.Insert(2);  // 1 2
  testee.Insert(3);  // 1 2 3

  EXPECT_EQ(1, testee.Peek());
  EXPECT_EQ(1, testee.Pop());  // 2 3
  EXPECT_EQ(2, testee.Peek());

  testee.Use(2);  // 3 2
  EXPECT_EQ(3, testee.Peek());
  EXPECT_EQ(3, testee.Pop());  // 2
  EXPECT_EQ(2, testee.Pop());
  EXPECT_TRUE(testee.IsEmpty());
}

}  // namespace

}  // namespace container_internal
}  // namespace nlib