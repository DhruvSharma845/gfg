#include <gtest/gtest.h>
#include "tests.h"

#include <level_order_traversal_in_spiral_form.h>
#include <queue_using_stacks.h>
#include <maximum_of_size_k_subarrays.h>
#include <tour_visiting_all_petrol_pumps.h>
#include <pair_with_given_sum.h>
#include <length_of_loop_in_linked_list.h>
#include <is_two_nodes_cousin.h>
#include <k_largest_elements_in_array.h>
#include <lowest_common_ancestor_bst.h>
#include <smallest_window_having_all_characters.h>
#include <depth_first_search.h>
#include <search_in_sorted_rotated_array.h>
#include <sort_elements_by_frequency.h>
#include <rearrange_same_characters_d_distance.h>
#include <largest_sum_contiguous_subarray.h>
#include <wildcard_character_matching.h>
#include <permutations_of_string.h>
#include <median_sorted_arrays_of_same_size.h>
#include <majority_element.h>
#include <middle_linked_list.h>
#include <nth_node_end_linked_list.h>
#include <reverse_stack_recursive.h>
#include <minimum_bracket_reversals_to_balance.h>
#include <sum_min_max_subarrays_size_k.h>
#include <sum_right_leaves.h>
#include <check_if_binary_tree_is_bst.h>
#include <sort_k_sorted_array.h>
#include <largest_subarray_with_equal_0_1.h>
#include <breadth_first_search.h>
#include <pair_sum_closest_zero.h>
#include <count_inversions.h>
#include <connect_n_ropes.h>
#include <maximum_sum_no_two_elements_adjacent.h>
#include <anagram_substring_search.h>
#include <rat_in_maze.h>
#include <count_frequencies_sorted_array.h>
#include <find_number_odd_times.h>
#include <find_missing_number.h>
#include <check_sll_is_palindrome.h>
#include <next_greater_element.h>
#include <negative_integer_window_size_k.h>
#include <inorder_successor_binary_tree.h>
#include <inorder_successor_bst.h>
#include <merge_k_sorted_arrays.h>
#include <four_elements_with_sum_x.h>
#include <detect_cycle_directed_graph.h>
#include <ceiling_sorted_array.h>
#include <segregate_zeroes_ones_array.h>
#include <minimum_number_of_platforms.h>
#include <maximum_size_submatrix_with_all_1s.h>

template <typename T>
void testArrays(const std::vector<T>& result, const std::vector<T>& expected) {
    ASSERT_EQ(expected.size(), result.size());
    for(int i = 0; i < result.size(); ++i) {
        EXPECT_EQ(result[i], expected[i]);
    }
}

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
    auto* root = bt.getRoot().get();
    root->addChild(3, Dir::Left);
    root->addChild(5, Dir::Right);

    root->getLeft()->addChild(7, Dir::Left);
    root->getLeft()->addChild(8, Dir::Right);

    root->getRight()->addChild(1, Dir::Left);
    root->getRight()->addChild(3, Dir::Right);

    CousinsInBinaryTree cbt;

    EXPECT_EQ(true, cbt.isCousin(bt.getRoot().get(), root->getLeft()->getLeft().get(), root->getRight()->getLeft().get()));
    EXPECT_EQ(false, cbt.isCousin(bt.getRoot().get(), root->getLeft()->getLeft().get(), root->getRight().get()));
}

TEST(KLargestElementsArray, SampleArray) {
    KLargestElementsArray ka;
    std::vector<int> v{1, 23, 12, 9, 30, 2, 50};
    auto res = ka.getKLargestElements(v, 3);
    std::sort(res.begin(), res.end(), std::greater<int>());

    std::vector<int> expectedRes{50, 30, 23};
    ASSERT_EQ(res.size(), expectedRes.size());
    for(int i = 0; i < res.size(); ++i) {
        EXPECT_EQ(res[i], expectedRes[i]);
    }
}

TEST(LowestCommonAncestorBST, SampleTree) {
    BinarySearchTree<int> bst;
    bst.insert(20);
    bst.insert(8);
    bst.insert(22);
    bst.insert(4);
    bst.insert(12);
    bst.insert(10);
    bst.insert(14);

    LowestCommonAncestorBST lca;
    EXPECT_EQ(12, lca.getLCA(bst.getRoot().get(), 10, 14));
    EXPECT_EQ(8, lca.getLCA(bst.getRoot().get(), 8, 14));
}

TEST(SmallestWindowWithAllCharsOfPattern, SampleStringAndPattern) {
    SmallestWindowWithAllCharsOfPattern swp;
    ASSERT_EQ(swp.getSmallestSubstring(std::string{"this is a test string"}, std::string{"tist"}), std::string{"t stri"});
    ASSERT_EQ(swp.getSmallestSubstring(std::string{"this is a test string"}, std::string{"xyz"}), std::string{""});
}

TEST(DepthFirstSearch, SampleGraph) {
    UndirectedUnweightedGraph<int> g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    DepthFirstSearch<int> dfs;
    std::vector<int> result = dfs.doDFS(g, 0);
    ASSERT_EQ(4, result.size());
    std::vector<int> expectedRes{0, 1, 2, 3};
    for(int i = 0; i < result.size(); ++i) {
        EXPECT_EQ(result[i], expectedRes[i]);
    }
}

TEST(SearchInSortedAndRotatedArray, SampleArray) {
    SearchInSortedAndRotatedArray ssra;
    auto [isFound, index] = ssra.getIndex(std::vector<int>{5,6,7,8,9,10,1,2,3}, 3);
    EXPECT_EQ(isFound, true);
    EXPECT_EQ(index, 8);
}

TEST(SortArrayByFrequency, SampleArray) {
    std::vector<int> arr{2, 5, 2, 8, 5, 6, 8, 8};
    SortArrayByFrequency saf;
    saf.doSort(arr);

    std::vector<int> expectedRes{8, 8, 8, 2, 2, 5, 5, 6};
    ASSERT_EQ(expectedRes.size(), arr.size());
    for(int i = 0; i < arr.size(); ++i) {
        EXPECT_EQ(arr[i], expectedRes[i]);
    }
}

TEST(RearrangeCharactersDDistanceAway, SampleString) {
    RearrangeCharactersDDistanceAway rc;
    ASSERT_EQ("bcabca", rc.doRearrange("aacbbc", 3));
    ASSERT_EQ("eskeskegoegrf", rc.doRearrange("geeksforgeeks", 3));
    ASSERT_EQ("", rc.doRearrange("aaa", 3));
}

TEST(LargestSumOfContiguousSubarray, SampleArray) {
    std::vector<int> v{-2, -3, 4, -1, -2, 1, 5, -3};
    LargestSumOfContiguousSubarray ls;
    ASSERT_EQ(7, ls.getMaximumSum(v));
}

TEST(WildcardPatternMatcher, SampleStringsAndPatterns) {
    WildcardPatternMatcher wpm;
    EXPECT_EQ(true, wpm.doesMatch("geeks", "g*ks"));
    EXPECT_EQ(false, wpm.doesMatch("gee", "g*k"));
    EXPECT_EQ(true, wpm.doesMatch("geeks", "ge?ks"));
}

TEST(PermutationsOfString, SampleString) {
    PermutationsOfString ps;
    std::vector<std::string> res = ps.getAllPermutations("ABC");

    ASSERT_EQ(6, res.size());
    std::vector<std::string> expectedRes{"ABC", "ACB", "BAC", "BCA", "CBA", "CAB"};
    for(int i = 0; i < res.size(); ++i) {
        EXPECT_EQ(res[i], expectedRes[i]);
    }
}

TEST(MedianOfSameSizedSortedArrays, SampleArrays) {
    MedianOfSameSizedSortedArrays mss;
    std::vector<int> a{1, 6, 7, 8};
    std::vector<int> b{2, 3, 4, 5};
    ASSERT_EQ(4, mss.getMedian(a, b));
}

TEST(MajorityElement, SampleArray) {
    std::vector<int> v{3, 3, 4, 2, 4, 4, 2, 4, 4};
    MajorityElement me;
    ASSERT_EQ(4, me.getMajorityElement(v));
}

TEST(MiddleOfLinkedList, SampleList) {
    SinglyLinkedList<int> sll;
    sll.addHead(1);
    auto* head = sll.getHead();
    head->setNext(new SLLNode<int>(2, nullptr));
    head->getNext()->setNext(new SLLNode<int>(3, nullptr));
    head->getNext()->getNext()->setNext(new SLLNode<int>(4, nullptr));
    head->getNext()->getNext()->getNext()->setNext(new SLLNode<int>(5, nullptr));
    MiddleOfLinkedList mll;
    auto* result = mll.getMiddle(sll);
    ASSERT_TRUE(result != nullptr);
    ASSERT_EQ(result->getData(), 3);
}

TEST(NthNodeFromEndSinglyLinkedList, SampleLinkedList) {
    SinglyLinkedList<int> sll;
    sll.addHead(1);
    auto* head = sll.getHead();
    head->setNext(new SLLNode<int>(2, nullptr));
    head->getNext()->setNext(new SLLNode<int>(3, nullptr));
    head->getNext()->getNext()->setNext(new SLLNode<int>(4, nullptr));

    NthNodeFromEndSinglyLinkedList nn;
    const auto& result = nn.getNthNodeFromEnd(sll, 3);
    ASSERT_TRUE(result.has_value());
    ASSERT_EQ(result.value()->getData(), 2);
}

TEST(RecursiveStackReversal, SampleStack) {
    std::stack<int> st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    RecursiveStackReversal rsr;
    rsr.doReversal(st);

    std::stack<int> expectedSt;
    expectedSt.push(1);
    expectedSt.push(2);
    expectedSt.push(3);
    expectedSt.push(4);
    ASSERT_EQ(st.size(), expectedSt.size());
    while(!expectedSt.empty()) {
        EXPECT_EQ(expectedSt.top(), st.top());
        expectedSt.pop();
        st.pop();
    }

}

TEST(MinBracketReversalsToBalance, SampleExpression) {
    MinBracketReversalsToBalance mbr;
    ASSERT_EQ(3, mbr.getCount("}{{}}{{{"));
    ASSERT_EQ(2, mbr.getCount("{{{{"));
    ASSERT_EQ(1, mbr.getCount("{{{{}}"));
}

TEST(SumMinMaxOfSubarraysOfSizeK, SampleArray) {
    std::vector<int> v{2, 5, -1, 7, -3, -1, -2};
    SumMinMaxOfSubarraysOfSizeK smm;
    ASSERT_EQ(14, smm.getSum(v, 3));
}

TEST(SumOfRightLeavesInBinaryTree, SampleTree) {
    BinaryTree<int> bt;
    bt.addRoot(1);
    BinaryTreeNode<int>* root = bt.getRoot().get();
    root->addChild(2, BinaryTreeNode<int>::Direction::Left);
    root->addChild(3, BinaryTreeNode<int>::Direction::Right);

    root->getLeft()->addChild(4, BinaryTreeNode<int>::Direction::Left);
    root->getLeft()->addChild(5, BinaryTreeNode<int>::Direction::Right);
    root->getLeft()->getLeft()->addChild(2, BinaryTreeNode<int>::Direction::Right);

    root->getRight()->addChild(8, BinaryTreeNode<int>::Direction::Right);
    root->getRight()->getRight()->addChild(7, BinaryTreeNode<int>::Direction::Right);

    SumOfRightLeavesInBinaryTree srl;
    ASSERT_EQ(14, srl.getSumOfRightLeaves(bt));
}

TEST(IsBinaryTreeBST, SampleTreePositive) {
    BinaryTree<int> bt;
    bt.addRoot(4);
    BinaryTreeNode<int>* root = bt.getRoot().get();
    root->addChild(2, BinaryTreeNode<int>::Direction::Left);
    root->addChild(5, BinaryTreeNode<int>::Direction::Right);

    root->getLeft()->addChild(1, BinaryTreeNode<int>::Direction::Left);
    root->getLeft()->addChild(3, BinaryTreeNode<int>::Direction::Right);
    
    IsBinaryTreeBST ibt;
    ASSERT_TRUE(ibt.doCheck(bt));
}

TEST(IsBinaryTreeBST, SampleTreeNegative) {
    BinaryTree<int> bt;
    bt.addRoot(4);
    BinaryTreeNode<int>* root = bt.getRoot().get();
    root->addChild(2, BinaryTreeNode<int>::Direction::Left);
    root->addChild(0, BinaryTreeNode<int>::Direction::Right);

    root->getLeft()->addChild(1, BinaryTreeNode<int>::Direction::Left);
    root->getLeft()->addChild(3, BinaryTreeNode<int>::Direction::Right);
    
    IsBinaryTreeBST ibt;
    ASSERT_FALSE(ibt.doCheck(bt));
}

TEST(KSortedArraySorter, SampleArray) {
    std::vector<int> v{6, 5, 3, 2, 8, 10, 9};
    KSortedArraySorter ksas;
    ksas.doSort(v, 3);

    std::vector<int> expectedRes{2, 3, 5, 6, 8, 9, 10};
    ASSERT_EQ(expectedRes.size(), v.size());
    
    for(int i = 0; i < v.size(); ++i) {
        EXPECT_EQ(v[i], expectedRes[i]);
    }
}

TEST(LargestSubarrayWithEqualZeroesOnes, SampleArray) {
    LargestSubarrayWithEqualZeroesOnes ls;
    auto res1 = ls.getIndices({1, 0, 1, 1, 1, 0, 0});
    ASSERT_TRUE(res1.has_value());
    EXPECT_EQ(res1.value().first, 1);
    EXPECT_EQ(res1.value().second, 6);

    auto res2 = ls.getIndices({1, 1, 1, 1});
    ASSERT_FALSE(res2.has_value());
}

TEST(BreadthFirstSearch, SampleGraph) {
    UndirectedUnweightedGraph<int> g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    BreadthFirstSearch<int> bfs;
    std::vector<int> result = bfs.doBFS(g, 2);
    ASSERT_EQ(4, result.size());
    std::vector<int> expectedRes{2, 0, 3, 1};
    for(int i = 0; i < result.size(); ++i) {
        EXPECT_EQ(result[i], expectedRes[i]);
    }
}

TEST(PairSumClosestToZero, SampleArray) {
    PairSumClosestToZero psc;
    std::vector<int> v{1, 60, -10, 70, -80, 85};
    auto res = psc.getPair(v);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(res.value().first, -80);
    EXPECT_EQ(res.value().second, 85);
}

TEST(CountInversions, SampleArrays) {
    CountInversions ci;
    ASSERT_EQ(5, ci.getInversionCount({1, 20, 6, 4, 5}));
    ASSERT_EQ(6, ci.getInversionCount({8, 4, 2, 1}));
}

TEST(ConnectNRopes, SampleArray) {
    ConnectNRopes cnr;
    ASSERT_EQ(29, cnr.getMinimumCost({4,3,2,6}));
}

TEST(MaximumSumSuchNoTwoAdjacent, SampleArray) {
    MaximumSumSuchNoTwoAdjacent ms;
    ASSERT_EQ(110, ms.getSum({5, 5, 10, 100, 10, 5}));
    ASSERT_EQ(13, ms.getSum({3, 2, 7, 10}));
}

TEST(AnagramSubstringSearch, SampleStrings) {
    AnagramSubstringSearch ass;
    std::vector<int> result = ass.getIndices("BACDGABCDA", "ABCD");

    ASSERT_EQ(3, result.size());
    std::vector<int> expectedRes{0, 5, 6};
    for(int i = 0; i < result.size(); ++i) {
        EXPECT_EQ(result[i], expectedRes[i]);
    }
}

TEST(RatInMaze, SampleMaze) {
    RatInMaze rim;
    std::vector<std::vector<int>> v{
        { 1, 0, 0, 0 },
        { 1, 1, 0, 1 },
        { 0, 1, 0, 0 },
        { 1, 1, 1, 1 }
    };
    auto result = rim.findPath(v);
    std::vector<std::vector<int>> expectedResult{
        { 1, 0, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 1, 1, 1 }
    };
    ASSERT_TRUE(result == expectedResult);
}

TEST(FrequencyCountSortedArray, SampleArrays) {
    FrequencyCountSortedArray fcsa;
    ASSERT_EQ(4, fcsa.getCount({1, 1, 2, 2, 2, 2, 3}, 2));
    ASSERT_EQ(2, fcsa.getCount({1, 1, 2, 2, 2, 2, 3}, 1));
    ASSERT_EQ(0, fcsa.getCount({1, 1, 2, 2, 2, 2, 3}, 4));
}

TEST(NumberOccuringOddNumOfTimes, SampleArray) {
    NumberOccuringOddNumOfTimes noo;
    ASSERT_EQ(3, noo.getNumber({1, 2, 3, 2, 3, 1, 3}));
    ASSERT_EQ(5, noo.getNumber({5, 7, 2, 7, 5, 2, 5}));
}

TEST(FindMissingNumber, SampleArray) {
    FindMissingNumber fmn;
    ASSERT_EQ(5, fmn.searchMissing({1, 2, 4, 6, 3, 7, 8}, 8));
    ASSERT_EQ(4, fmn.searchMissing({1, 2, 3, 5}, 5));
}

TEST(IsSLLPalindrome, SampleList) {
    SinglyLinkedList<char> sll;
    sll.addHead('R');
    auto* head = sll.getHead();
    head->setNext(new SLLNode<char>('A', nullptr));
    head->getNext()->setNext(new SLLNode<char>('D', nullptr));
    head->getNext()->getNext()->setNext(new SLLNode<char>('A', nullptr));
    head->getNext()->getNext()->getNext()->setNext(new SLLNode<char>('R', nullptr));

    IsSLLPalindrome isp;
    ASSERT_TRUE(isp.doCheck(sll));
}

TEST(NextGreaterElement, SampleArrays) {
    NextGreaterElement nge;
    auto result = nge.getNextGreaterElements({ 4 , 5 , 2 , 25 });

    testArrays<int>(result, {5, 25, 25, -1});
}

TEST(NegativeIntegerInWindow, SampleArray) {
    NegativeIntegerInWindow niw;
    auto result = niw.getNegativeIntegersInAllWindows({12, -1, -7, 8, -15, 30, 16, 28}, 3);
    testArrays<int>(result, {-1, -1, -7, -15, -15, 0});
}

TEST(InorderSuccessorBinaryTree, SampleTree) {
    BinaryTree<int> bt;
    using Dir = BinaryTreeNode<int>::Direction;
    bt.addRoot(1);
    auto* root = bt.getRoot().get();
    root->addChild(2, Dir::Left);
    root->addChild(3, Dir::Right);

    root->getLeft()->addChild(4, Dir::Left);
    root->getLeft()->addChild(5, Dir::Right);

    root->getRight()->addChild(6, Dir::Right);

    InorderSuccessorBinaryTree isbt;
    
    ASSERT_EQ(2, isbt.getInorderSuccessor(bt, 4));
    ASSERT_EQ(1, isbt.getInorderSuccessor(bt, 5));
}

TEST(InorderSuccessorBST, SampleTree) {
    BinarySearchTree<int> bst;
    bst.insert(20);
    bst.insert(8);
    bst.insert(22);
    bst.insert(4);
    bst.insert(12);
    bst.insert(10);
    bst.insert(14);

    InorderSuccessorBST isb;
    ASSERT_EQ(10, isb.getInorderSuccessor(bst,8));
    ASSERT_EQ(12, isb.getInorderSuccessor(bst,10));
}

TEST(MergeKSortedArrays, SampleTest) {
    MergeKSortedArrays mksa;
    auto res = mksa.doSort({{1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11}});
    testArrays(res, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 });
}

TEST(FourElementsWithGivenSum, SampleArray) {
    FourElementsWithGivenSum fegs;
    auto elements = fegs.getElements({10, 2, 3, 4, 5, 9, 7, 8}, 23);
    ASSERT_TRUE(elements.has_value());
    auto [first, second, third, fourth] = elements.value();
    ASSERT_EQ(2, first);
    ASSERT_EQ(3, second);
    ASSERT_EQ(8, third);
    ASSERT_EQ(10, fourth);
}

TEST(CycleDetectorGraph, SampleGraph) {
    DirectedUnweightedGraph<int> g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    CycleDetectorGraph<int> cdg;
    ASSERT_TRUE(cdg.hasCycle(g));
}

TEST(CeilingInSortedArray, SampleArrays) {
    CeilingInSortedArray cisa;
    ASSERT_EQ(1, cisa.getCeil({1, 2, 8, 10, 10, 12, 19}, 1));
    ASSERT_EQ(8, cisa.getCeil({1, 2, 8, 10, 10, 12, 19}, 5));
    ASSERT_EQ(std::nullopt, cisa.getCeil({1, 2, 8, 10, 10, 12, 19}, 20));
}

TEST(SegregateZeroesAndOnes, SampleArray) {
    std::vector<int> arr{0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    SegregateZeroesAndOnes szo;
    szo.doSegregate(arr);
    testArrays(arr, {0, 0, 0, 0, 0, 1, 1, 1, 1, 1});
}

TEST(MinimumNumberOfPlatforms, SampleArray) {
    MinimumNumberOfPlatforms mnp;
    ASSERT_EQ(3, mnp.getNumber({{900, 910}, {940, 1200}, {950, 1120}, {1100, 1130}, {1500, 1900}, {1800,2000}}));
}

TEST(MaxSubmatrixWithAllOnes, SampleMatrix) {
    MaxSubmatrixWithAllOnes::Matrix mat{
        { 0, 1, 1, 0, 1 }, 
        { 1, 1, 0, 1, 0 },
        { 0, 1, 1, 1, 0 }, 
        { 1, 1, 1, 1, 0 },
        { 1, 1, 1, 1, 1 }, 
        { 0, 0, 0, 0, 0 }
    };
    MaxSubmatrixWithAllOnes mswao;
    auto result = mswao.getMaximumSubmatrix(mat);
    auto [x, y, width, height] = result;
    EXPECT_EQ(2, x);
    EXPECT_EQ(1, y);
    EXPECT_EQ(3, width);
    EXPECT_EQ(3, height);
}

int runAllTests() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}