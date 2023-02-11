#pragma once

#include <vector>

class MatrixInSpiralFormat {
public:
    std::vector<int> getSpiralForm(const std::vector<std::vector<int>>& matrix);
};

std::vector<int> MatrixInSpiralFormat::getSpiralForm(const std::vector<std::vector<int>>& matrix) {
    int startRow = 0;
    int endRow = matrix.size() - 1;

    int startCol = 0;
    int endCol = matrix[0].size() - 1;

    std::vector<int> res;
    res.reserve(matrix.size() * matrix[0].size());

    while(startRow < endRow && startCol < endCol) {
        for(int col = startCol; col <= endCol; ++col) {
            res.push_back(matrix[startRow][col]);
        }
        ++startRow;

        for(int row = startRow; row <= endRow; ++row) {
            res.push_back(matrix[row][endCol]);
        }
        --endCol;

        if(startRow <= endRow) {
            for(int col = endCol; col >= startCol; --col) {
                res.push_back(matrix[endRow][col]);
            }
            --endRow;
        }
        if(startCol <= endCol) {
            for(int row = endRow; row >= startRow; --row) {
                res.push_back(matrix[row][startCol]);
            }
            ++startCol;
        }
    }

    return res;
}