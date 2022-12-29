#pragma once

#include <string>

class MaxLengthPrefixThatIsSubsequence {
public:
    int getMaxLength(const std::string& str1, const std::string& str2);
};

int MaxLengthPrefixThatIsSubsequence::getMaxLength(const std::string& str1, const std::string& str2) {
    int j = 0;
    int i = 0;
    for(; i < str1.size() && j < str2.size(); ++i) {
        while(j < str2.size() && str2[j] != str1[i]) {
            ++j;
        }
        if(j < str2.size()) {
            ++j;
        }
        else {
            break;
        }
    }
    return i;
}