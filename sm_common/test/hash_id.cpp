#include <algorithm>

#include <gtest/gtest.h>

#include "sm/hash_id.hpp"

using namespace sm;

TEST(SmCommonTestSuite,hashId_different) {
  HashId a, b;
  EXPECT_NE(a,b);
}

TEST(SmCommonTestSuite,hashId_validity) {
  HashId a, b;
  EXPECT_TRUE(a.isValid());
  a.setInvalid();
  EXPECT_FALSE(a.isValid());
  b.setInvalid();
  EXPECT_EQ(a, b);
}

TEST(SmCommonTestSuite,hashId_string) {
  HashId a, b;
  std::string as(a.hexString()), bs(b.hexString());
  EXPECT_NE(as,bs);
  EXPECT_EQ(as.length(), 32);
  EXPECT_EQ(bs.length(), 32);
}
