#include <gtest/gtest.h>
#include "tests.h"

/**
 * TEST(x, y) {
 *  GTEST_ASSERT_EQ(func(),z)
 * }
 */

int runAllTests() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}