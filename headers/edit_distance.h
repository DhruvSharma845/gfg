#pragma once

#include <string>
#include <vector>
#include <algorithm>

class EditDistance {
public:
    int getEditsRequired(const std::string& str1, const std::string& str2);
};

int EditDistance::getEditsRequired(const std::string& str1, const std::string& str2) {
    std::vector<std::vector<int>> dpTable(str1.size() + 1, std::vector<int>(str2.size() + 1, 0));

    for(int i = 1; i <= str1.size(); ++i) {
        dpTable[i][0] = i;
    }
    for(int j = 1; j <= str2.size(); ++j) {
        dpTable[0][j] = j;
    }

    for (int i = 1; i <= str1.size(); ++i) {
        for(int j = 1; j <= str2.size(); ++j) {
            if(str1[i - 1] == str2[j - 1]) {
                dpTable[i][j] = dpTable[i-1][j-1];
            }
            else {
                dpTable[i][j] = std::min(
                    std::min(
                        dpTable[i-1][j-1], // replace
                        dpTable[i-1][j] // remove
                    ),
                    dpTable[i][j-1] // insert
                ) + 1;
            }
        }
    }

    return dpTable[str1.size()][str2.size()];
}