#include <gtest/gtest.h>
#include "tests.h"

#include "headers/level_order_traversal_in_spiral_form.h"

/**
 * TEST(x, y) {
 *  GTEST_ASSERT_EQ(func(),z)
 * }
 */

TEST(LevelOrderTraversalInSpiralForm, SampleTree) {
    LevelOrderTraversalInSpiralForm lot;
    auto v = lot.getLOTInSpiralForm();

    const std::vector<int> expectedV{1, 2, 3, 4, 5, 6, 7};

    ASSERT_EQ(v.size(), expectedV.size());
    for(int i = 0; i < v.size(); ++i) {
        EXPECT_EQ(v[i], expectedV[i]);
    }
}

int runAllTests() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}