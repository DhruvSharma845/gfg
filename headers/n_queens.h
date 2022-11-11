#pragma once

#include <vector>

class NQueens {
public:
    using Chessboard = std::vector<std::vector<int>>;

    Chessboard findPositions(int N); 
private:
    bool recurseOnBoard(NQueens::Chessboard& board, int currentRow, std::vector<bool>& isColumnOccupied, std::vector<bool>& leftSidedDiagonals, std::vector<bool>& rightSidedDiagonals);
};

bool NQueens::recurseOnBoard(NQueens::Chessboard& board,
 int currentRow,
 std::vector<bool>& isColumnOccupied,
 std::vector<bool>& leftSidedDiagonals,
 std::vector<bool>& rightSidedDiagonals) {
     int N = board.size();
     if(currentRow == N) {
         return true;
     }

     for(int i = 0; i < N; ++i) {
         if(isColumnOccupied[i] == false && leftSidedDiagonals[currentRow - i + N] == false && rightSidedDiagonals[currentRow + i] == false) {
            board[currentRow][i] = 1;
            isColumnOccupied[i] = true;
            leftSidedDiagonals[currentRow - i + N] = true;
            rightSidedDiagonals[currentRow + i] = true;
            if(recurseOnBoard(board, currentRow + 1, isColumnOccupied, leftSidedDiagonals, rightSidedDiagonals) == true) {
                return true;
            }
            board[currentRow][i] = 0;
            isColumnOccupied[i] = false;
            leftSidedDiagonals[currentRow - i + N] = false;
            rightSidedDiagonals[currentRow + i] = false;
         }
     }
     return false;
}


NQueens::Chessboard NQueens::findPositions(int N) {
    NQueens::Chessboard board(N, std::vector<int>(N, 0));

    std::vector<bool> isColumnOccupied(N, false);
    std::vector<bool> leftSidedDiagonals(2 * N, false);
    std::vector<bool> rightSidedDiagonals(2 * N, false);
    recurseOnBoard(board, 0, isColumnOccupied, leftSidedDiagonals, rightSidedDiagonals);
    return board;
}