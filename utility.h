#pragma once

#include <vector>
#include <gtest/gtest.h>

template <typename T>
void testArrays(const std::vector<T>& result, const std::vector<T>& expected) {
    ASSERT_EQ(expected.size(), result.size());
    for(int i = 0; i < result.size(); ++i) {
        EXPECT_EQ(result[i], expected[i]);
    }
}
