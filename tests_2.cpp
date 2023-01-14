#include <queue>
#include <gtest/gtest.h>

#include "utility.h"

#include <max_length_prefix_that_is_subsequence.h>
#include <sudoku.h>
#include <minimum_in_sorted_rotated_array.h>
#include <segregate_even_odd.h>
#include <find_duplicate_in_linear_time_and_constant_space.h>
#include <equilibrium_index_array.h>
#include <pairwise_swap_nodes.h>
#include <stock_span_problem.h>
#include <interleave_halves_of_queue.h>
#include <convert_bt_node_stores_sum_right_subtree.h>
#include <merge_bsts_with_limited_space.h>
#include <check_array_is_heap.h>
#include <vertical_order_traversal_binary_tree.h>
#include <strongly_connected_components.h>
#include <elements_appear_more_than_nbyk.h>
#include <pancake_sorting.h>
#include <fractional_knapsack.h>

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

TEST(SudokuSolver, SampleBoard) {
    SudokuSolver::SudokuBoardType initialBoard{ 
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    SudokuSolver ss;
    auto resBoard = ss.solve(initialBoard);

    SudokuSolver::SudokuBoardType expectedBoard{
        {3, 1, 6, 5, 7, 8, 4, 9, 2},
        {5, 2, 9, 1, 3, 4, 7, 6, 8},
        {4, 8, 7, 6, 2, 9, 5, 3, 1},
        {2, 6, 3, 4, 1, 5, 9, 8, 7},
        {9, 7, 4, 8, 6, 3, 1, 2, 5},
        {8, 5, 1, 7, 9, 2, 6, 4, 3}, 
        {1, 3, 8, 9, 4, 7, 2, 5, 6},
        {6, 9, 2, 3, 5, 1, 8, 7, 4},
        {7, 4, 5, 2, 8, 6, 3, 1, 9}
    };
    for(int i = 0; i < resBoard.size(); ++i) {
        testArrays(resBoard[i], expectedBoard[i]);
    }
}

TEST(MinimumInSortedAndRotatedArray, SampleArrays) {
    MinimumInSortedAndRotatedArray msra;
    ASSERT_EQ(msra.getMin({5, 6, 1, 2, 3, 4}), 1);
    ASSERT_EQ(msra.getMin({2, 1}), 1);
}

TEST(EvenOddSegregator, SampleArray) {
    EvenOddSegregator eos;
    auto res = eos.doSegregate({12, 34, 45, 9, 8, 90, 3});
    std::vector<int> expectedRes{12, 34, 8, 90, 45, 9, 3};
    testArrays(res, expectedRes);
}

TEST(FindDuplicatesIn1ToN, SampleArray) {
    std::vector<int> v{1, 2, 3, 6, 3, 6, 1};
    FindDuplicatesIn1ToN fd;
    auto res = fd.findDuplicates(v);
    std::vector<int> expectedRes{1, 3, 6};
    testArrays(res, expectedRes);
}

TEST(EquilibriumIndex, SampleArrays) {
    EquilibriumIndex ei;
    ASSERT_EQ(6, ei.getIndex({-7, 1, 5, 2, -4, 3, 0}));
    ASSERT_EQ(-1, ei.getIndex({1,2,3}));
}

TEST(PairwiseSwapNodes, SampleLL) {
    SinglyLinkedList<int> sll;
    sll.addHead(1);
    auto* head = sll.getHead();
    head->setNext(new SLLNode<int>(2, nullptr));
    head->getNext()->setNext(new SLLNode<int>(3, nullptr));
    head->getNext()->getNext()->setNext(new SLLNode<int>(4, nullptr));
    head->getNext()->getNext()->getNext()->setNext(new SLLNode<int>(5, nullptr));
    head->getNext()->getNext()->getNext()->getNext()->setNext(new SLLNode<int>(6, nullptr));

    PairwiseSwapNodes<int> psn;
    psn.doSwap(sll);

    ASSERT_EQ(2, sll.getHead()->getData());
    ASSERT_EQ(1, sll.getHead()->getNext()->getData());
    ASSERT_EQ(4, sll.getHead()->getNext()->getNext()->getData());
    ASSERT_EQ(3, sll.getHead()->getNext()->getNext()->getNext()->getData());
}

TEST(StockSpan, SamplePricesArray) {
    StockSpan ss;
    auto res = ss.findCountOfLowPriceDays({10, 4, 5, 90, 120, 80});
    std::vector<int> expectedRes{1, 1, 2, 4, 5, 1};
    testArrays(res, expectedRes);
}

TEST(HalvesInterleaving, SampleQueue) {
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    HalvesInterleaving hi;
    hi.doInterleaving(q);
    ASSERT_EQ(6, q.size());
    ASSERT_EQ(1, q.front());
    q.pop();
    ASSERT_EQ(4, q.front());
    q.pop();
    ASSERT_EQ(2, q.front());
}

TEST(ConvertBinaryTreeNodeStoresSumOfRight, SampleBT) {
    BinaryTree<int> bt;
    bt.addRoot(1);
    BinaryTreeNode<int>* root = bt.getRoot().get();
    root->addChild(2, BinaryTreeNode<int>::Direction::Left);
    root->addChild(3, BinaryTreeNode<int>::Direction::Right);

    root->getLeft()->addChild(4, BinaryTreeNode<int>::Direction::Left);
    root->getLeft()->addChild(5, BinaryTreeNode<int>::Direction::Right);
    
    root->getRight()->addChild(6, BinaryTreeNode<int>::Direction::Right);
    
    ConvertBinaryTreeNodeStoresSumOfRight cb;
    cb.doConversion(bt);

    ASSERT_EQ(bt.getRoot()->getData(), 10);
    ASSERT_EQ(bt.getRoot()->getLeft()->getData(), 7);
    ASSERT_EQ(bt.getRoot()->getLeft()->getLeft()->getData(), 4);
    ASSERT_EQ(bt.getRoot()->getRight()->getData(), 9);
    ASSERT_EQ(bt.getRoot()->getRight()->getRight()->getData(), 6);
}

TEST(MergeBST, SampleBSTs) {
    BinarySearchTree<int> bst1;
    bst1.insert(8);
    bst1.insert(2);
    bst1.insert(10);
    bst1.insert(1);

    BinarySearchTree<int> bst2;
    bst2.insert(5);
    bst2.insert(3);
    bst2.insert(0);

    MergeBST mb;
    auto res = mb.getInorderOfMergedBSTS(bst1, bst2);
    std::vector<int> expectedRes{0, 1, 2, 3, 5, 8, 10};
    testArrays(res, expectedRes);
} 

TEST(IsArrayAHeap, SampleArrays) {
    IsArrayAHeap iah;
    ASSERT_TRUE(iah.doCheck({90, 15, 10, 7, 12, 2}));
    ASSERT_FALSE(iah.doCheck({9, 15, 10, 7, 12, 11}));
}

TEST(VerticalOrderTraversal, SampleTree) {
    BinaryTree<int> bt;
    bt.addRoot(1);
    BinaryTreeNode<int>* root = bt.getRoot().get();
    root->addChild(2, BinaryTreeNode<int>::Direction::Left);
    root->addChild(3, BinaryTreeNode<int>::Direction::Right);

    root->getLeft()->addChild(4, BinaryTreeNode<int>::Direction::Left);
    root->getLeft()->addChild(5, BinaryTreeNode<int>::Direction::Right);
    
    root->getRight()->addChild(6, BinaryTreeNode<int>::Direction::Left);
    root->getRight()->addChild(7, BinaryTreeNode<int>::Direction::Right);

    root->getRight()->getRight()->addChild(8, BinaryTreeNode<int>::Direction::Left);

    VerticalOrderTraversal vot;
    auto res = vot.getVerticalOrder(bt);

    ASSERT_EQ(5, res.size());
    std::map<int, std::vector<int>> expectedRes{
        std::make_pair<int, std::vector<int>>(-2, {4}),
        std::make_pair<int, std::vector<int>>(-1, {2}),
        std::make_pair<int, std::vector<int>>(0, {1,5,6}),
        std::make_pair<int, std::vector<int>>(1, {3, 8}),
        std::make_pair<int, std::vector<int>>(2, {7}),
    };

    for(const auto& [horDist, elems]: expectedRes) {
        ASSERT_TRUE(res.find(horDist) != res.end());
        testArrays(res.at(horDist), elems);
    }
}

TEST(StronglyConnectedComponents, SampleGraph) {
    DirectedUnweightedGraph<int> g(5);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    
    StronglyConnectedComponents scc;
    StronglyConnectedComponents::SCCType res = scc.findSCC(g);
    StronglyConnectedComponents::SCCType expectedRes{
        {0, 1, 2},
        {3},
        {4}
    };
    ASSERT_EQ(res.size(), expectedRes.size());
    for(int i = 0; i < res.size(); ++i) {
        testArrays(res[i], expectedRes[i]);
    }
}

TEST(ElementsThatAppearMoreThanNKTimes, SampleArray) {
    ElementsThatAppearMoreThanNKTimes enk;
    auto res = enk.findElements({3, 1, 2, 2, 1, 2, 3, 3}, 4);
    std::vector<int> expectedRes{2, 3};

    testArrays(res, expectedRes);
}

TEST(PancakeSorting, SampleArray) {
    PancakeSorting ps;
    auto res = ps.doSort({23, 10, 20, 11, 12, 6, 7});
    std::vector<int> expectedRes{ 6, 7, 10, 11, 12, 20, 23};
    testArrays(res, expectedRes);
}

TEST(FractionalKnapsack, SampleWeightsValues) {
    FractionalKnapsack fk;
    std::vector<std::pair<int, int>> weightsAndValues{
        {10, 60}, 
        {20, 100}, 
        {30, 120}
    };
    ASSERT_EQ(fk.findOptimalValue(weightsAndValues, 50), 240);
}