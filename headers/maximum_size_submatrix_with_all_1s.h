#pragma once

#include <tuple>
#include <algorithm>
#include <numeric>

class MaxSubmatrixWithAllOnes {
public:
    using Matrix = std::vector<std::vector<int>>;
    using MatrixCoordinates = std::tuple<int, int, int, int>;

    MatrixCoordinates getMaximumSubmatrix(const Matrix& matrix);
};

MaxSubmatrixWithAllOnes::MatrixCoordinates MaxSubmatrixWithAllOnes::getMaximumSubmatrix(const MaxSubmatrixWithAllOnes::Matrix& matrix) {
    Matrix dpTable(matrix.size(), std::vector<int>(matrix[0].size(), 0));

    int maxFound = std::numeric_limits<int>::min();
    int maxRowCoord = -1;
    int maxColCoord = -1;

    for(int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if(i == 0 || j == 0) {
                dpTable[i][j] = matrix[i][j];
            }
            else if(matrix[i][j] == 1) {
                dpTable[i][j] = 1 + std::min({dpTable[i-1][j-1], dpTable[i][j-1], dpTable[i-1][j]});
            }
            if(dpTable[i][j] > maxFound) {
                maxFound = dpTable[i][j];
                maxRowCoord = i;
                maxColCoord = j;
            }
        }
    }

    return std::make_tuple(maxRowCoord - maxFound + 1,maxColCoord - maxFound + 1,maxFound,maxFound);
}