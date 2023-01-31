#pragma once

#include <string>
#include <unordered_map>

class RearrangeCharactersToMakePalindrome {
public:
    bool isPalindromable(const std::string& str);
};

bool RearrangeCharactersToMakePalindrome::isPalindromable(const std::string& str) {
    std::unordered_map<char, int> freqCount;
    for(const auto& ch: str) {
        freqCount[ch]++;
    }

    auto countOfOdd = int{0};
    for(const auto& [ch, freq]: freqCount) {
        if(freq % 2 != 0) {
            ++countOfOdd;
        }
    }
    return (countOfOdd <= 1);
}