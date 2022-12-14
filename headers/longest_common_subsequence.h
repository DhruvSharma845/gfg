#pragma once

#include <string_view>
#include <vector>

class LongestCommonSubsequence {
public:
    std::string getLCS(std::string_view str1, std::string_view str2);
};

std::string LongestCommonSubsequence::getLCS(std::string_view str1, std::string_view str2) {
    std::vector<std::vector<int>> dpTable(str1.size() + 1, std::vector<int>(str2.size() + 1, 0));
    for(int i = 1; i <= str1.length(); ++i) {
        for (int j = 1; j <= str2.length(); ++j) {
            if(str1[i - 1] == str2[j - 1]) {
                dpTable[i][j] = 1 + dpTable[i-1][j-1];
            }
            else {
                dpTable[i][j] = std::max(dpTable[i][j-1], dpTable[i-1][j]);
            }
        }
    }
    std::string lcs{""};
    int i = str1.size(), j = str2.size();
    while(i > 0 && j > 0) {
        if(str1[i-1] == str2[j-1]) {
            lcs.push_back(str1[i-1]);
            --i;
            --j;
        }
        else {
            if(dpTable[i-1][j] > dpTable[i][j-1]) {
                --i;
            }
            else {
                --j;
            }
        }
    }
    std::reverse(lcs.begin(), lcs.end());
    return lcs;
}