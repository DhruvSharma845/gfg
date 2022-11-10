#pragma once 

#include <vector>
#include <string>
#include <utility>

class SearchWordIn2DGrid {
private: 
    bool searchWord(const std::vector<std::string>& grid, const std::pair<int, int>& initialCoord, const std::string& word);
public:
    std::vector<std::pair<int,int>> getCoordinates(const std::vector<std::string>& grid, const std::string& word);
private:
    static std::vector<std::pair<int, int>> directionChanges;
};

std::vector<std::pair<int, int>> SearchWordIn2DGrid::directionChanges{
    {0, 1}, // east
    {1, 1}, // south east
    {1, 0}, // south
    {1, -1}, // south west
    {0, -1}, // west
    {-1, -1}, // north west
    {-1, 0}, //north
    {-1, 1}, // north east
};

bool SearchWordIn2DGrid::searchWord(
    const std::vector<std::string>& grid, 
    const std::pair<int, int>& initialCoord, 
    const std::string& word)
{
    auto [currentRow, currentCol] = initialCoord;
    if(grid[currentRow][currentCol] == word[0]) {
        for(int i = 0; i < directionChanges.size(); ++i) {
            auto [rowChange, colChange] = directionChanges[i];
            int newRow = currentRow;
            int newCol = currentCol;
            int j = 1;
            for(; j < word.size(); ++j) {
                newRow += rowChange;
                newCol += colChange;
                if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()) {
                    if(grid[newRow][newCol] != word[j]) {
                        break;
                    }
                }
                else {
                    break;
                }
            }
            if(j == word.size()) {
                return true;
            }
        }
    }
    return false;
}

std::vector<std::pair<int,int>> SearchWordIn2DGrid::getCoordinates(const std::vector<std::string>& grid, const std::string& word) {
    std::vector<std::pair<int, int>> result;
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[0].size(); ++j) {
            auto pr{std::make_pair(i, j)};
            if(searchWord(grid, pr, word) == true) {
                result.push_back(pr);
            }
        }
    }
    return result;
}