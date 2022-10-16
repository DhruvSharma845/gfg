#include <gtest/gtest.h>
#include "tests.h"

#include <level_order_traversal_in_spiral_form.h>
#include <queue_using_stacks.h>
#include <maximum_of_size_k_subarrays.h>
#include <tour_visiting_all_petrol_pumps.h>

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

TEST(SizeKSubarrayMaximums, SampleArray) {
    SizeKSubarrayMaximums sm;
    std::vector<int> arr{1, 2, 3, 1, 4, 5, 4, 3, 2};
    auto res = sm.getMaximumOfAllSubarrays(arr, 3);

    const std::vector<int> expectedRes{3, 3, 4, 5, 5, 5, 4};

    ASSERT_EQ(res.size(), expectedRes.size());
    for(int i = 0; i < res.size(); ++i) {
        EXPECT_EQ(res[i], expectedRes[i]);
    }
}

TEST(PetrolPumpsTour, SampleInfo) {

    std::vector<std::pair<int, int>> info{{4,6}, {6,3}, {3,7}};

    PetrolPumpsTour ppt;
    auto resultIndex = ppt.getIndexOfPetrolPumpThatCoverAllPetrolPumps(info);
    ASSERT_EQ(2, resultIndex);
}

int runAllTests() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}