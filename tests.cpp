#include <gtest/gtest.h>
#include "tests.h"

#include <level_order_traversal_in_spiral_form.h>
#include <queue_using_stacks.h>

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

TEST(QueueUsingStack, TryOperations) {
    QueueUsingStack qus;
    qus.enqueue(1);
    qus.enqueue(2);
    qus.enqueue(3);

    EXPECT_EQ(1, qus.front());
    qus.dequeue();
    EXPECT_EQ(2, qus.front());
    qus.dequeue();
    EXPECT_EQ(3, qus.front());
    qus.dequeue();
    ASSERT_EQ(0, qus.size());
    EXPECT_EQ(std::numeric_limits<int>::min(), qus.front());
}

int runAllTests() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}