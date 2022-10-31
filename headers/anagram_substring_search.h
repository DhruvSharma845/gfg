#pragma once

#include <vector>
#include <algorithm>

class AnagramSubstringSearch {
public:
    std::vector<int> getIndices(const std::string& str, const std::string& pat);
};

std::vector<int> AnagramSubstringSearch::getIndices(const std::string& str, const std::string& pat) {
    std::vector<int> indices;

    std::vector<int> patCount(256, 0);
    for(const auto& ch: pat) {
        patCount[static_cast<int>(ch)]++;
    }

    int i{0};
    std::vector<int> strCount(256, 0); 
    for(;i < pat.size(); ++i) {
        strCount[static_cast<int>(str[i])]++;
    }

    if(std::equal(strCount.begin(), strCount.end(), patCount.begin())) {
        indices.push_back(0);
    }

    for(; i < str.size(); ++i) {
        strCount[static_cast<int>(str[i])]++;
        strCount[static_cast<int>(str[i - pat.size()])]--;
        if(std::equal(strCount.begin(), strCount.end(), patCount.begin())) {
            indices.push_back(i - pat.size() + 1);
        }
    }
    
    return indices;
}