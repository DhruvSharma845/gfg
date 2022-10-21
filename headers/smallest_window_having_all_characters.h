#pragma once

#include <string>
#include <unordered_map>

class SmallestWindowWithAllCharsOfPattern {
public:
    std::string getSmallestSubstring(const std::string& str, const std::string& pat);
};

std::string SmallestWindowWithAllCharsOfPattern::getSmallestSubstring(const std::string& str, const std::string& pat) {
    std::unordered_map<char, int> patternMap;
    for(const auto& ch: pat) {
        patternMap[ch]++;
    }

    int start = 0;
    int finalStart = 0;
    int finalEnd = str.size() + 1;

    std::unordered_map<char, int> strMap;
    int countOfFoundChars = 0;
    for(auto i = 0; i < str.size(); ++i) {
        if(patternMap.find(str[i]) != patternMap.end()) {
            if(patternMap[str[i]] > strMap[str[i]]) {
                ++countOfFoundChars;
            }
            strMap[str[i]]++;
        }
        if(countOfFoundChars == pat.size()) {
            while(start <= i) {
                if(patternMap.find(str[start]) == patternMap.end()) {
                    ++start;
                }
                else if(patternMap.find(str[start]) != patternMap.end() &&
                    strMap[str[start]] > patternMap[str[start]]) {
                    strMap[str[start]]--;
                    ++start;
                }
                else {
                    break;
                }
            }
            if((finalEnd - finalStart) > (i - start)) {
                finalStart = start;
                finalEnd = i;
            } 
            if(patternMap.find(str[start]) != patternMap.end()) {
                strMap[str[start]]--;
                ++start;
                --countOfFoundChars;
            }
        }
    }
    if(finalEnd == str.size() + 1) {
        return std::string{""};
    }
    return str.substr(finalStart, finalEnd - finalStart + 1);
}