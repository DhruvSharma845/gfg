#pragma once

#include <vector>
#include <utility>

class AllPathsFromTopleftToBottomRight {
public:
    using Matrix = std::vector<std::vector<int>>;
    using Paths = std::vector<std::vector<int>>;
    std::vector<std::vector<int>> getAllPaths(const Matrix& matrix);
private:
    void traverseRecursively(const Matrix& matrix, std::pair<int, int> coord, Paths& res, std::vector<int>& currentPath);
};

AllPathsFromTopleftToBottomRight::Paths AllPathsFromTopleftToBottomRight::getAllPaths(const Matrix& matrix) {
    Paths resPaths;
    std::vector<int> curPath;
    curPath.push_back(matrix[0][0]);
    traverseRecursively(matrix, std::make_pair(0, 0), resPaths, curPath);
    return resPaths;
}

void AllPathsFromTopleftToBottomRight::traverseRecursively(const Matrix& matrix, std::pair<int, int> coord, Paths& res, std::vector<int>& currentPath) {
    auto& [row, col] = coord;
    if(row == matrix.size() - 1 && col == matrix[0].size() - 1) {
        res.push_back(currentPath);
        return;
    }
    if((col + 1) < matrix[0].size()) {
        currentPath.push_back(matrix[row][col + 1]);
        traverseRecursively(matrix, std::make_pair(row, col + 1), res, currentPath);
        currentPath.pop_back();
    }
    if((row + 1) < matrix.size()) {
        currentPath.push_back(matrix[row + 1][col]);
        traverseRecursively(matrix, std::make_pair(row + 1, col), res, currentPath);
        currentPath.pop_back();
    }
}