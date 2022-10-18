#include <gtest/gtest.h>
#include "tests.h"

#include <level_order_traversal_in_spiral_form.h>
#include <queue_using_stacks.h>
#include <maximum_of_size_k_subarrays.h>
#include <tour_visiting_all_petrol_pumps.h>
#include <pair_with_given_sum.h>
#include <length_of_loop_in_linked_list.h>
#include <is_two_nodes_cousin.h>

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

TEST(PairWithGivenSum, ArrayWhereExists) {
    std::vector<int> input{0, -1, 2, -3, 1};
    PairWithGivenSum pgs;
    ASSERT_EQ(pgs.isPairWithSumKExists(input, -2), true); 
}

TEST(PairWithGivenSum, ArrayWhereDoesNotExists) {
    std::vector<int> input{1, 2, 1, 0, 5};
    PairWithGivenSum pgs;
    ASSERT_EQ(pgs.isPairWithSumKExists(input, 0), false); 
}

TEST(LoopLengthLinkedList, SampleLL) {
    LoopLengthLinkedList ll;

    auto [hasLoop, loopCount] = ll.detectAndCountLoop();
    ASSERT_EQ(true, hasLoop);
    ASSERT_EQ(4, loopCount);
}

TEST(CousinsInBinaryTree, CheckBothPositiveAndNegativeCases) {
    BinaryTree<int> bt;
    using Dir = BinaryTreeNode<int>::Direction;
    bt.addRoot(6);
    auto* root = bt.getRoot();
    root->addChild(3, Dir::Left);
    root->addChild(5, Dir::Right);

    root->getLeft()->addChild(7, Dir::Left);
    root->getLeft()->addChild(8, Dir::Right);

    root->getRight()->addChild(1, Dir::Left);
    root->getRight()->addChild(3, Dir::Right);

    CousinsInBinaryTree cbt;

    EXPECT_EQ(true, cbt.isCousin(bt.getRoot(), root->getLeft()->getLeft(), root->getRight()->getLeft()));
    EXPECT_EQ(false, cbt.isCousin(bt.getRoot(), root->getLeft()->getLeft(), root->getRight()));
}


int runAllTests() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}