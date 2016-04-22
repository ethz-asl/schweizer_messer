#include <gtest/gtest.h>

#define NDEBUG
#define SM_ALWAYS_ASSERT
#include <sm/assert_macros.hpp>

TEST(SmCommonTestSuite,testAssertMacrosAlwaysAssert)
{
  SM_DEFINE_EXCEPTION(Exception, std::runtime_error);
  EXPECT_THROW( SM_ASSERT_TRUE_DBG(Exception, false, ""), Exception);
}
