#pragma once

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
#include <min_cost_path.h>
#include <find_patterns_101_in_string.h>
#include <all_paths_from_topleft_bottomright.h>
#include <missing_number_in_AP.h>
#include <max_ji_such_arrj_greater_arri.h>
#include <intersection_sorted_linked_list.h>
#include <merge_overlapping_intervals.h>
#include <smallest_multiple_made_of_0_9.h>
#include <binary_tree_sorted_level_wise.h>
#include <binary_tree_to_bst.h>
#include <merge_k_sorted_linked_lists.h>
#include <chars_rearrange_to_make_palindrome.h>
#include <eulerian_path_cycle.h>
#include <k_closest_elements_to_value.h>
#include <sort_numbers_from_1_to_n2.h>
#include <minimize_max_difference_between_heights.h>
#include <minimum_jumps_to_reach_end.h>
#include <min_shift_longest_common_prefix.h>
#include <strings_with_spaces.h>
#include <element_that_appears_once.h>
#include <matrix_spiral_format.h>
#include <merge_two_sorted_linked_lists.h>
#include <convert_infix_to_postfix.h>
#include <level_order_with_direction_change.h>
#include <check_if_two_trees_are_mirror.h>
#include <correct_two_swapped_nodes_bst.h>
#include <minimum_sum_from_digits_array.h>
#include <first_repeating_element_array.h>
#include <longest_path_dag.h>
#include <next_greater_with_same_digits.h>
#include <sort_array_order_by_other_array.h>
#include <smallest_number_with_digits_and_sum.h>
#include <coin_change.h>

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

TEST(MinimumCostPath, SampleCosts) {
    MinimumCostPath mcp;
    ASSERT_EQ(8, mcp.calculateCost({ 
        { 1, 2, 3 }, 
        { 4, 8, 2 }, 
        { 1, 5, 3 } 
    }));
}

TEST(FindPatternsOf101, SampleStrings) {
    FindPatternsOf101 fp;
    auto res1 = fp.findCount("1101001");
    ASSERT_TRUE(res1.has_value());
    ASSERT_EQ(2, res1.value());
    ASSERT_EQ(0, fp.findCount("10201").value());
}

TEST(AllPathsFromTopleftToBottomRight, SampleMatrix) {
    AllPathsFromTopleftToBottomRight ap;
    AllPathsFromTopleftToBottomRight::Matrix m{ 
        {1, 2, 3}, 
        {4, 5, 6} 
    };
    auto res = ap.getAllPaths(m);
    AllPathsFromTopleftToBottomRight::Paths expectedRes{
        {1, 2, 3, 6 }, 
        {1, 2, 5, 6 }, 
        {1, 4, 5, 6 } 
    };
    ASSERT_EQ(res.size(), expectedRes.size());
    for(int i = 0; i < expectedRes.size(); ++i) {
        testArrays(res[i], expectedRes[i]);
    }
}

TEST(MissingNumberInAP, SampleAPs) {
    MissingNumberInAP mn;
    auto res = mn.findMissingNumber({2, 4, 8, 10, 12, 14});
    ASSERT_TRUE(res.has_value());
    ASSERT_EQ(res.value(), 6);

    res = mn.findMissingNumber({1, 6, 11, 16, 21, 31});
    ASSERT_TRUE(res.has_value());
    ASSERT_EQ(res.value(), 26);
}

TEST(MaxJISuchThatArrjGreaterThanArri, SampleArrays) {
    MaxJISuchThatArrjGreaterThanArri mji;
    auto res1 = mji.findJMinusI({34, 8, 10, 3, 2, 80, 30, 33, 1});
    ASSERT_TRUE(res1.has_value());
    ASSERT_EQ(6, res1.value());
    auto res2 = mji.findJMinusI({9, 2, 3, 4, 5, 6, 7, 8, 18, 0});
    ASSERT_TRUE(res2.has_value());
    ASSERT_EQ(8, res2.value());
    ASSERT_FALSE(mji.findJMinusI({6, 5, 4, 3, 2, 1}).has_value());
}

TEST(SortedLinkedListsIntersection, SampleLLs) {
    SinglyLinkedList<int> sll;
    sll.addHead(1);
    auto* head = sll.getHead();
    head->setNext(new SLLNode<int>(2, nullptr));
    head->getNext()->setNext(new SLLNode<int>(3, nullptr));
    head->getNext()->getNext()->setNext(new SLLNode<int>(4, nullptr));
    head->getNext()->getNext()->getNext()->setNext(new SLLNode<int>(6, nullptr));
    

    SinglyLinkedList<int> sll2;
    sll2.addHead(2);
    head = sll2.getHead();
    head->setNext(new SLLNode<int>(4, nullptr));
    head->getNext()->setNext(new SLLNode<int>(7, nullptr));
    head->getNext()->getNext()->setNext(new SLLNode<int>(8, nullptr));
    
    SortedLinkedListsIntersection slli;
    SinglyLinkedList<int> res = slli.findIntersection(sll, sll2);

    ASSERT_TRUE(res.getHead() != nullptr);
    ASSERT_EQ(res.getHead()->getData(), 2);
    ASSERT_EQ(res.getHead()->getNext()->getData(), 4);
}

TEST(MergeOverlappingIntervals, SampleIntervals) {
    MergeOverlappingIntervals::IntervalArray ia{{1,3},{2,4},{6,8},{9,10}};
    MergeOverlappingIntervals moi;
    auto res = moi.mergeIntervals(ia);
    MergeOverlappingIntervals::IntervalArray expectedRes{{1, 4}, {6, 8}, {9, 10}};
    ASSERT_EQ(expectedRes.size(), res.size());
    testArrays(res, expectedRes);
}

TEST(SmallestMultipleMadeOf0And9, SampleNumbers) {
    SmallestMultipleMadeOf0And9 sm;
    ASSERT_EQ(90, sm.findMultipleOf(5));
    ASSERT_EQ(9009, sm.findMultipleOf(7));
}

TEST(IsBinaryTreeLevelSorted, SampleBinaryTree) {
    BinaryTree<int> bt;
    bt.addRoot(1);
    BinaryTreeNode<int>* root = bt.getRoot().get();
    root->addChild(2, BinaryTreeNode<int>::Direction::Left);
    root->addChild(3, BinaryTreeNode<int>::Direction::Right);

    root->getLeft()->addChild(4, BinaryTreeNode<int>::Direction::Left);
    root->getLeft()->addChild(5, BinaryTreeNode<int>::Direction::Right);
    
    root->getRight()->addChild(6, BinaryTreeNode<int>::Direction::Left);
    root->getRight()->addChild(7, BinaryTreeNode<int>::Direction::Right);

    root->getLeft()->getRight()->addChild(8, BinaryTreeNode<int>::Direction::Left);
    root->getRight()->getRight()->addChild(9, BinaryTreeNode<int>::Direction::Left);

    IsBinaryTreeLevelSorted ibt;
    ASSERT_TRUE(ibt.isLevelWiseSorted(bt));
}

TEST(BinaryTreeToBST, SampleBinaryTree) {
    BinaryTree<int> bt;
    bt.addRoot(10);
    BinaryTreeNode<int>* root = bt.getRoot().get();
    root->addChild(2, BinaryTreeNode<int>::Direction::Left);
    root->addChild(7, BinaryTreeNode<int>::Direction::Right);

    root->getLeft()->addChild(8, BinaryTreeNode<int>::Direction::Left);
    root->getLeft()->addChild(4, BinaryTreeNode<int>::Direction::Right);
    
    BinaryTreeToBST btb;
    btb.convert(bt);

    ASSERT_EQ(bt.getRoot()->getData(), 8);
    ASSERT_EQ(bt.getRoot()->getLeft()->getData(), 4);
    ASSERT_EQ(bt.getRoot()->getLeft()->getLeft()->getData(), 2);
    ASSERT_EQ(bt.getRoot()->getLeft()->getRight()->getData(), 7);
    ASSERT_EQ(bt.getRoot()->getRight()->getData(), 10);
}

TEST(MergeKSortedLinkedLists, SampleLists) {
    SinglyLinkedList<int> sll1;
    sll1.addHead(1);
    auto* head = sll1.getHead();
    head->setNext(new SLLNode<int>(3, nullptr));
    head->getNext()->setNext(new SLLNode<int>(5, nullptr));
    
    SinglyLinkedList<int> sll2;
    sll2.addHead(2);
    head = sll2.getHead();
    head->setNext(new SLLNode<int>(7, nullptr));
    head->getNext()->setNext(new SLLNode<int>(9, nullptr));

    SinglyLinkedList<int> sll3;
    sll3.addHead(3);
    head = sll3.getHead();
    head->setNext(new SLLNode<int>(8, nullptr));
    head->getNext()->setNext(new SLLNode<int>(10, nullptr));

    std::vector<SinglyLinkedList<int>> v{sll1, sll2, sll3};

    MergeKSortedLinkedLists mks;
    SinglyLinkedList<int> res = mks.doMerge(v);
    ASSERT_TRUE(res.getHead() != nullptr);
    ASSERT_EQ(res.getHead()->getData(), 1);
    ASSERT_EQ(res.getHead()->getNext()->getData(), 2);
    ASSERT_EQ(res.getHead()->getNext()->getNext()->getData(), 3);
}

TEST(RearrangeCharactersToMakePalindrome, SampleStrings) {
    RearrangeCharactersToMakePalindrome rc;
    ASSERT_TRUE(rc.isPalindromable("geeksogeeks"));
    ASSERT_FALSE(rc.isPalindromable("geeksforgeeks"));
}

TEST(EulerianPathAndCycleInUndirectedGraph, SampleGraphEulerPath) {
    UndirectedUnweightedGraph<int> g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    EulerianPathAndCycleInUndirectedGraph ep;
    ASSERT_TRUE(ep.hasEulerianPath(g1));
    ASSERT_FALSE(ep.hasEulerianCycle(g1));
}

TEST(EulerianPathAndCycleInUndirectedGraph, SampleGraphEulerCycle) {
    EulerianPathAndCycleInUndirectedGraph ep;
    UndirectedUnweightedGraph<int> g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);

    ASSERT_FALSE(ep.hasEulerianPath(g2));
    ASSERT_TRUE(ep.hasEulerianCycle(g2));
}

TEST(KClosestElements, SampleArray) {
    KClosestElements kc;
    auto res = kc.findKClosest({12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56}, 35, 4);

    std::vector<int> expectedRes{39, 30, 42, 45};
    testArrays(res, expectedRes);
}

TEST(NumberSorterFrom0ToN2, SampleArray) {
    NumberSorterFrom0ToN2 ns;
    auto res = ns.doSort({0, 23, 14, 12, 9});
    std::vector<int> expectedRes{0, 9, 12, 14, 23};
    testArrays(res, expectedRes);
}

TEST(MinimizeMaxDifferenceBwHeights, SampleArray) {
    MinimizeMaxDifferenceBwHeights mm;
    ASSERT_EQ(8, mm.getDifference({1, 5, 15, 10}, 3));
}

TEST(MinimumJumpsToReachEnd, SampleArrays) {
    MinimumJumpsToReachEnd mj;
    ASSERT_EQ(3, mj.getMinimumJumps({1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}));
    ASSERT_EQ(10, mj.getMinimumJumps({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
}

TEST(MinimumShiftForLongestCommonPrefix, SampleStrings) {
    MinimumShiftForLongestCommonPrefix ms;
    ASSERT_EQ(1, ms.getMinShift("geeks", "dgeek"));
    ASSERT_EQ(5, ms.getMinShift("practicegeeks", "coderpractice"));
}

TEST(PossibleStringsWithSpaces, SampleString) {
    PossibleStringsWithSpaces ps;
    auto res = ps.getPossibleStrings("ABCD");
    std::vector<std::string> expectedRes{
        "ABCD",
        "ABC D",
        "AB CD",
        "AB C D",
        "A BCD",
        "A BC D",
        "A B CD",
        "A B C D"
    };
    testArrays(res, expectedRes);
}

TEST(FindElementThatAppearsOnce, SampleArrays) {
    FindElementThatAppearsOnce fe;
    ASSERT_EQ(4, fe.findElement({1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}));
    ASSERT_EQ(8, fe.findElement({1, 1, 3, 3, 4, 4, 5, 5, 7, 7, 8}));
}

TEST(MatrixInSpiralFormat, SampleMatrix) {
    MatrixInSpiralFormat msf;
    auto res = msf.getSpiralForm({
        {1,    2,   3,   4},
        {5,    6,   7,   8},
        {9,   10,  11,  12},
        {13,  14,  15,  16 }
    });
    std::vector<int> expectedRes{1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};
    testArrays(res, expectedRes);
}

TEST(Merge2SortedLinkedLists, SampleLinkedLists) {
    SinglyLinkedList<int> sll;
    sll.addHead(1);
    auto* head = sll.getHead();
    head->setNext(new SLLNode<int>(4, nullptr));
    head->getNext()->setNext(new SLLNode<int>(7, nullptr));
    head->getNext()->getNext()->setNext(new SLLNode<int>(8, nullptr));
    head->getNext()->getNext()->getNext()->setNext(new SLLNode<int>(10, nullptr));
    

    SinglyLinkedList<int> sll2;
    sll2.addHead(2);
    head = sll2.getHead();
    head->setNext(new SLLNode<int>(3, nullptr));
    head->getNext()->setNext(new SLLNode<int>(6, nullptr));
    head->getNext()->getNext()->setNext(new SLLNode<int>(9, nullptr));

    Merge2SortedLinkedLists m2s;
    SinglyLinkedList<int> res = m2s.doMerge(sll, sll2); 

    ASSERT_TRUE(res.getHead() != nullptr);
    ASSERT_EQ(res.getHead()->getData(), 1);
    ASSERT_EQ(res.getHead()->getNext()->getData(), 2);
    ASSERT_EQ(res.getHead()->getNext()->getNext()->getData(), 3);
    ASSERT_EQ(res.getHead()->getNext()->getNext()->getNext()->getData(), 4);
}

TEST(InfixToPostfixConverter, SampleExpressions) {
    InfixToPostfixConverter ipc;
    ASSERT_EQ(ipc.getPostfix("A+B*C+D"), "ABC*+D+");
    ASSERT_EQ(ipc.getPostfix("((A+B)-C*(D/E)+F)"), "AB+CDE/*-F+");
    ASSERT_EQ(ipc.getPostfix("a+b*(c^d-e)^(f+g*h)-i"), "abcd^e-fgh*+^*+i-");
}

TEST(LevelOrderTraversalWithDirectionChange, SampleTree) {
    BinaryTree<int> bt;
    bt.addRoot(1);
    BinaryTreeNode<int>* root = bt.getRoot().get();
    root->addChild(2, BinaryTreeNode<int>::Direction::Left);
    root->addChild(3, BinaryTreeNode<int>::Direction::Right);

    root->getLeft()->addChild(4, BinaryTreeNode<int>::Direction::Left);
    
    root->getRight()->addChild(5, BinaryTreeNode<int>::Direction::Right);

    root->getLeft()->getLeft()->addChild(6, BinaryTreeNode<int>::Direction::Left);
    root->getLeft()->getLeft()->addChild(7, BinaryTreeNode<int>::Direction::Right);

    root->getRight()->getRight()->addChild(8, BinaryTreeNode<int>::Direction::Left);
    root->getRight()->getRight()->addChild(9, BinaryTreeNode<int>::Direction::Right);

    LevelOrderTraversalWithDirectionChange lot;
    auto res = lot.getTraversal(bt);
    std::vector<int> expectedRes{1,2,3,5,4,9,8,7,6};
    testArrays(res, expectedRes);

}

TEST(AreTreesMirror, SampleBinaryTrees) {
    BinaryTree<int> bt1;
    bt1.addRoot(1);
    BinaryTreeNode<int>* root = bt1.getRoot().get();
    root->addChild(2, BinaryTreeNode<int>::Direction::Left);
    root->addChild(3, BinaryTreeNode<int>::Direction::Right);

    root->getLeft()->addChild(4, BinaryTreeNode<int>::Direction::Left);
    root->getLeft()->addChild(5, BinaryTreeNode<int>::Direction::Right);
    
    root->getRight()->addChild(6, BinaryTreeNode<int>::Direction::Left);
    root->getRight()->addChild(7, BinaryTreeNode<int>::Direction::Right);

    BinaryTree<int> bt2;
    bt2.addRoot(1);
    root = bt2.getRoot().get();
    root->addChild(3, BinaryTreeNode<int>::Direction::Left);
    root->addChild(2, BinaryTreeNode<int>::Direction::Right);

    root->getLeft()->addChild(7, BinaryTreeNode<int>::Direction::Left);
    root->getLeft()->addChild(6, BinaryTreeNode<int>::Direction::Right);
    
    root->getRight()->addChild(5, BinaryTreeNode<int>::Direction::Left);
    root->getRight()->addChild(4, BinaryTreeNode<int>::Direction::Right);

    AreTreesMirror atm;
    ASSERT_TRUE(atm.checkMirrors(bt1, bt2));
}

TEST(CorrectTwoSwappedNodesBST, SampleBST) {
    BinarySearchTree<int> bst1;
    bst1.insert(6);
    bst1.insert(10);
    bst1.insert(2);
    bst1.insert(1);
    bst1.insert(3);
    bst1.insert(7);
    bst1.insert(12);
    
    bst1.getRoot()->getLeft()->setData(10);
    bst1.getRoot()->getRight()->setData(2);

    CorrectTwoSwappedNodesBST cts;
    cts.doCorrection(bst1);

    ASSERT_EQ(2, bst1.getRoot()->getLeft()->getData());
    ASSERT_EQ(10, bst1.getRoot()->getRight()->getData());
}

TEST(MinimumSumFromDigitsOfArray, SampleArray) {
    MinimumSumFromDigitsOfArray ms;
    ASSERT_EQ(604, ms.getMinSum({6, 8, 4, 5, 2, 3}));
}

TEST(FirstRepeatingElement, SampleArrays) {
    FirstRepeatingElement fre;

    ASSERT_EQ(fre.getElement({10, 5, 3, 4, 3, 5, 6}), 5);
    ASSERT_EQ(fre.getElement({6, 10, 5, 4, 9, 120, 4, 6, 10}), 6);
}

TEST(LongestPathInDAG, SampleGraph) {
    DirectedWeightedGraph dg(6);
    dg.addEdge(0, 1, 5);
    dg.addEdge(0, 2, 3);
    dg.addEdge(1, 3, 6);
    dg.addEdge(1, 2, 2);
    dg.addEdge(2, 4, 4);
    dg.addEdge(2, 5, 2);
    dg.addEdge(2, 3, 7);
    dg.addEdge(3, 5, 1);
    dg.addEdge(3, 4, -1);
    dg.addEdge(4, 5, -2);

    LongestPathInDAG lp;
    auto res = lp.getDistancesFromSource(dg, 1);
    std::vector<int> expectedRes{std::numeric_limits<int>::max(), 0, 2, 9, 8, 10};
    testArrays(res, expectedRes);
}

TEST(NextGreaterNumberWithSameDigits, SampleNumbers) {
    NextGreaterNumberWithSameDigits ngn;
    using namespace std::string_literals;
    ASSERT_EQ("251678"s, ngn.getNextGreater("218765"));
    ASSERT_EQ("536479"s, ngn.getNextGreater("534976"));
    ASSERT_EQ("1243"s, ngn.getNextGreater("1234"));
}

TEST(SortArrayOrderedByAnotherArray, SampleArray) {
    SortArrayOrderedByAnotherArray sa;
    auto res = sa.doSort({2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}, {2, 1, 8, 3});
    std::vector<int> expectedRes{2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9};
    testArrays(res, expectedRes);
}

TEST(SmallestNumWithDigitsAndSum, SampleValues) {
    SmallestNumWithDigitsAndSum sn;
    ASSERT_EQ(18, sn.getSmallestNum(2, 9));
    ASSERT_EQ(299, sn.getSmallestNum(3, 20));
}

TEST(CoinChange, SampleCoins) {
    CoinChange cc;
    ASSERT_EQ(4, cc.getWaysToMakeChange(4, {1,2,3}));
    ASSERT_EQ(5, cc.getWaysToMakeChange(10, {2, 5, 3, 6}));
}