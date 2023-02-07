#pragma once

#include <string>
#include <vector>

class PossibleStringsWithSpaces {
private:
    void recursivelyFindStrings(const std::string& str, std::vector<std::string>& res, std::string& currentStr, int index);
public:
    std::vector<std::string> getPossibleStrings(const std::string& str);
};

void PossibleStringsWithSpaces::recursivelyFindStrings(
    const std::string& str, 
    std::vector<std::string>& res, 
    std::string& currentStr, 
    int index) {

        if(index == str.length()) {
            res.push_back(currentStr);
            return;
        }

        currentStr.push_back(str[index]);
        recursivelyFindStrings(str, res, currentStr, index + 1);

        currentStr.pop_back();
        currentStr.push_back(' ');
        currentStr.push_back(str[index]);
        recursivelyFindStrings(str, res, currentStr, index + 1);
        currentStr.pop_back();
        currentStr.pop_back();
}

std::vector<std::string> PossibleStringsWithSpaces::getPossibleStrings(const std::string& str) {
    std::vector<std::string> res;
    std::string currentStr;
    currentStr.push_back(str[0]);
    recursivelyFindStrings(str, res, currentStr, 1);
    return res;
}