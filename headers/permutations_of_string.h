#pragma once

#include <vector>
#include <string>
#include <algorithm>

class PermutationsOfString {
private:
    void getAllPermutationsUtil(std::string& str, std::vector<std::string>& results, int index);
public:
    std::vector<std::string> getAllPermutations(const std::string& str);
};

std::vector<std::string> PermutationsOfString::getAllPermutations(const std::string& str) {
    std::vector<std::string> resultArr;
    std::string clonedStr{str};
    getAllPermutationsUtil(clonedStr, resultArr, 0);
    return resultArr;
}

void PermutationsOfString::getAllPermutationsUtil(std::string& str, std::vector<std::string>& results, int index) {
    if(index >= str.size()) {
        results.push_back(str);
    }
    for(auto i = index; i < str.size(); ++i) {
        std::swap(str[index], str[i]);
        getAllPermutationsUtil(str, results, index + 1);
        std::swap(str[index], str[i]);
    }
}