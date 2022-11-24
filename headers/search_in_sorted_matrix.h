#pragma once

#include <utility>
#include <vector>
#include <optional>

class SearchInSortedMatrix {
public:
    using Matrix = std::vector<std::vector<int>>;
    std::optional<std::pair<int, int>> findElement(const Matrix& matrix, int X);
};

std::optional<std::pair<int, int>> SearchInSortedMatrix::findElement(const Matrix& matrix, int X) {
    std::pair<int, int> coord = {0, matrix[0].size() - 1};
    auto& [x, y] = coord;
    while(x < matrix.size() && y >= 0) {
        if(matrix[x][y] == X) {
            return coord;
        }
        else if(matrix[x][y] > X) {
            --y;
        }
        else if(matrix[x][y] < X) {
            ++x;
        }
    }
    return std::nullopt;
}