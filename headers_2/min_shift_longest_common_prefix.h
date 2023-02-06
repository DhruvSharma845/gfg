#pragma once

#include <string>
#include <utility>

class MinimumShiftForLongestCommonPrefix {
private:
    std::pair<int, int> doKMP(const std::string& str1, const std::string& str2);
public:
    int getMinShift(const std::string& str1, const std::string& str2);
};

std::pair<int, int> MinimumShiftForLongestCommonPrefix::doKMP(const std::string& str1, const std::string& str2) {
    std::vector<int> preprocessed(str1.size() + 1, 0);

    int k = 0;
    for(int i = 2; i <= str1.size(); ++i) {
        while(k > 0 && str1[k] != str1[i-1]) {
            k = preprocessed[k];
        }
        if(str1[k] == str1[i-1]) {
            ++k;
        }
        preprocessed[i] = k;
    }
    int pos = -1;
    int currentLen = -1;
    for (int j = 0, i = 0; i < str2.size(); i++) {
        while (j > 0 && str1[j] != str2[i])
            j = preprocessed[j];
        if (str1[j] == str2[i])
            j++;
 
        if (j > currentLen) {
            currentLen = j;
            pos = i - j + 1;
        }
    }

    return std::make_pair(pos, currentLen);
}

int MinimumShiftForLongestCommonPrefix::getMinShift(const std::string& str1, const std::string& str2) {
    return doKMP(str1, str2 + str2).first;
}