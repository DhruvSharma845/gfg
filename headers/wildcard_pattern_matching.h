#pragma once

#include <string_view>

class WildcardPatternMatching {
public:
    bool doesMatch(std::string_view text, std::string_view pattern);
};

bool WildcardPatternMatching::doesMatch(std::string_view text, std::string_view pattern) {
    std::vector<std::vector<bool>> dpTable(text.size() + 1, std::vector<bool>(pattern.size() + 1, false));

    dpTable[0][0] = true;

    for (int j = 1; j <= pattern.size(); j++) {
        if (pattern[j - 1] == '*') {
            dpTable[0][j] = dpTable[0][j - 1];
        }
    }

    for(int i = 1; i <= text.size(); ++i) {
        for(int j = 1; j <= pattern.size(); ++j) {
            if(text[i-1] == pattern[j-1] || pattern[j-1] == '?') {
                dpTable[i][j] = dpTable[i-1][j-1];
            }
            else if(pattern[j-1] == '*') {
                dpTable[i][j] = dpTable[i-1][j] || dpTable[i][j-1];
            }
        }
    }
    return dpTable[text.size()][pattern.size()];
}