#pragma once

#include <vector>

class RowWithMaximumOnes {
public:
    using Matrix = std::vector<std::vector<int>>;

    int getRowIndex(const Matrix& matrix); 
};

int RowWithMaximumOnes::getRowIndex(const RowWithMaximumOnes::Matrix& matrix) {
    int maxOnesRowIndex = -1;
    int currentMaxOnes = 0;
    int colIndex = matrix[0].size() - 1;
    int rowIndex = 0;
    while(rowIndex < matrix.size() && colIndex >= 0) {
        if(matrix[rowIndex][colIndex] == 1) {
            if(matrix.size() - colIndex > currentMaxOnes) {
                currentMaxOnes = matrix.size() - colIndex;
                maxOnesRowIndex = rowIndex;
            }
            --colIndex;
        }
        else {
            ++rowIndex;
        }
    }
    return maxOnesRowIndex;
}