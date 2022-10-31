#pragma once

#include <vector>
#include <utility>


class RatInMaze {
public:
    using Matrix = std::vector<std::vector<int>>;

    Matrix findPath(const Matrix& maze);
private:
    bool findPathUtil(const Matrix& maze, Matrix& result, std::pair<int, int> coord);
    bool isValid(std::pair<int, int>& coord, int N, int M, Matrix& result, const Matrix& maze);
};

bool RatInMaze::isValid(std::pair<int, int>& coord, int N, int M, Matrix& result, const Matrix& maze) {
    return (
        coord.first >= 0 && 
        coord.first < N && 
        coord.second >= 0 && 
        coord.second < M &&
        result[coord.first][coord.second] == 0 &&
        maze[coord.first][coord.second] == 1
    );
}
bool RatInMaze::findPathUtil(const Matrix& maze, Matrix& result, std::pair<int, int> coord) {
    if(coord.first == maze.size() - 1 && coord.second == maze.size() - 1)  {
        return true;
    }
    auto newCoord = std::make_pair(coord.first, coord.second + 1);
    if(isValid(newCoord, maze.size(), maze[0].size(), result, maze) == true) {
        result[newCoord.first][newCoord.second] = 1;
        int resRight = findPathUtil(maze, result, newCoord);
        if(resRight == true) {
            return true;
        }
        result[newCoord.first][newCoord.second] = 0;
    }

    auto newCoord1 = std::make_pair(coord.first + 1, coord.second);
    if(isValid(newCoord1, maze.size(), maze[0].size(), result, maze) == true) {
        result[newCoord1.first][newCoord1.second] = 1;
        int resBottom = findPathUtil(maze, result, newCoord1);
        if(resBottom == true) {
            return true;
        }
        result[newCoord1.first][newCoord1.second] = 0;
    }
    return false;
}

auto RatInMaze::findPath(const Matrix& maze) -> Matrix {
    Matrix result{maze.size(), std::vector<int>(maze[0].size(), 0)};
    result[0][0] = 1;
    findPathUtil(maze, result, std::make_pair(0,0));
    return result;
}