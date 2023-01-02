#include <gtest/gtest.h>

#include "utility.h"

#include <max_length_prefix_that_is_subsequence.h>
#include <sudoku.h>
#include <minimum_in_sorted_rotated_array.h>
#include <segregate_even_odd.h>
#include <find_duplicate_in_linear_time_and_constant_space.h>
#include <equilibrium_index_array.h>
#include <pairwise_swap_nodes.h>

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

