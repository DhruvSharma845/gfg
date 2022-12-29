#include <gtest/gtest.h>

#include "utility.h"

#include <max_length_prefix_that_is_subsequence.h>

/**
 * TEST(x, y) {
 *  GTEST_ASSERT_EQ(func(),z)
 * }
 */

TEST(MaxLengthPrefixThatIsSubsequence, SampleStrings) {
    MaxLengthPrefixThatIsSubsequence mlp;
    ASSERT_EQ(3, mlp.getMaxLength("digger", "biggerdiagram"));
    ASSERT_EQ(4, mlp.getMaxLength("geeksforgeeks", "agbcedfeitk"));
}

