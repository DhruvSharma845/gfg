#pragma once

#include <utility>
#include <vector>

class AllOccurrencesOfWordInMatrix {
public:
    using Coordinate = std::pair<int, int>;
    using WordCoordinates = std::vector<Coordinate>;
    using Matrix = std::vector<std::vector<char>>;

    std::vector<WordCoordinates> getAllOccurences(const Matrix& matrix, const std::string& word);
    void checkRecursively(const Matrix& matrix, const std::string& word, int currentI, int currentJ, int wordIndex, std::vector<WordCoordinates>& res, WordCoordinates& wc, std::pair<int, int> prevCoord);

    static std::vector<std::pair<int, int>> directionChanges;
};

std::vector<std::pair<int, int>> AllOccurrencesOfWordInMatrix::directionChanges{
    {0, 1}, // east
    {1, 1}, // south east
    {1, 0}, // south
    {1, -1}, // south west
    {0, -1}, // west
    {-1, -1}, // north west
    {-1, 0}, //north
    {-1, 1}, // north east
};

void AllOccurrencesOfWordInMatrix::checkRecursively(
    const Matrix& matrix, 
    const std::string& word, 
    int currentI, 
    int currentJ, 
    int wordIndex,
    std::vector<WordCoordinates>& res,
    WordCoordinates& wc,
    std::pair<int, int> prevCoord) {
        if(wordIndex == word.size()) {
            res.push_back(wc);
            return;
        }
        for(const auto& [xInc, yInc] : directionChanges) {
            auto newI = currentI + xInc;
            auto newJ = currentJ + yInc;

            if(newI >= 0 && newI < matrix.size() && newJ >= 0 && newJ < matrix[0].size() && !(newI == prevCoord.first && newJ == prevCoord.second)) {
                if(matrix[newI][newJ] == word[wordIndex]) {
                    wc.push_back(std::make_pair(newI, newJ));
                    checkRecursively(matrix, word, newI, newJ, wordIndex + 1, res, wc, std::make_pair(currentI, currentJ));
                    wc.pop_back();
                }
            }
        }
}

auto AllOccurrencesOfWordInMatrix::getAllOccurences(const Matrix& matrix, const std::string& word) -> std::vector<WordCoordinates> {
    std::vector<WordCoordinates> res;
    for(int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if(matrix[i][j] == word[0]) {
                WordCoordinates wc;
                wc.push_back(std::make_pair(i, j));
                checkRecursively(matrix, word, i, j, 1, res, wc, std::make_pair(-1, -1));
            }
        }
    }
    return res;
}