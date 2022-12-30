#pragma once

#include <vector>

class SudokuSolver {
public:
    using SudokuBoardType = std::vector<std::vector<int>>;

    SudokuBoardType solve(const SudokuBoardType& board);
private:
    bool solveRecursively(const SudokuBoardType& board, int rowIndex, int colIndex, SudokuBoardType& resBoard);
    bool isValid(const SudokuBoardType& resBoard, int rowIndex, int colIndex, int value);
};

SudokuSolver::SudokuBoardType SudokuSolver::solve(const SudokuSolver::SudokuBoardType& board) {
    SudokuBoardType resBoard(board.begin(), board.end());
    solveRecursively(board, 0, 0, resBoard);
    return resBoard;
}

bool SudokuSolver::solveRecursively(const SudokuSolver::SudokuBoardType& board, int rowIndex, int colIndex, SudokuSolver::SudokuBoardType& resBoard) {
    if(rowIndex == board.size()) {
        return true;
    }
    int nextRowIndex = rowIndex;
    int nextColIndex = colIndex;
    if(colIndex < board[0].size() - 1) {
        ++nextColIndex;
    }
    else if(colIndex == board[0].size() - 1) {
        ++nextRowIndex;
        nextColIndex = 0;
    }
    if(resBoard[rowIndex][colIndex] != 0) {
        if(solveRecursively(board, nextRowIndex, nextColIndex, resBoard) == true) {
            return true;
        }
        return false;
    }
    int N = board.size();
    for(int i = 1; i <= N; ++i) {
        if(isValid(resBoard, rowIndex, colIndex, i) == true) {
            resBoard[rowIndex][colIndex] = i;
            if(solveRecursively(board, nextRowIndex, nextColIndex, resBoard) == true) {
                return true;
            }
            resBoard[rowIndex][colIndex] = 0;
        }
    }
    return false;
}

bool SudokuSolver::isValid(const SudokuSolver::SudokuBoardType& resBoard, int rowIndex, int colIndex, int value) {
    for(int j = 0; j < resBoard[0].size(); ++j) {
        if(resBoard[rowIndex][j] == value) {
            return false;
        }
    }
    for(int i = 0; i < resBoard.size(); ++i) {
        if(resBoard[i][colIndex] == value) {
            return false;
        }
    }

    int boxRowStart = (rowIndex / 3) * 3;
    int boxColStart = (colIndex / 3) * 3;
    for(int i = boxRowStart; i < boxRowStart + 3; ++i) {
        for(int j = boxColStart; j < boxColStart + 3; ++j) {
            if(resBoard[i][j] == value) {
                return false;
            }
        }
    }
    return true;
}