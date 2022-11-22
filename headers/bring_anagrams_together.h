#pragma once

#include <vector>
#include <string>
#include <unordered_map>

class AnagramsCollector {
public:
    std::vector<std::vector<std::string>> getAllAnagrams(const std::vector<std::string>& arr);
};

std::vector<std::vector<std::string>> AnagramsCollector::getAllAnagrams(const std::vector<std::string>& arr) {
    std::unordered_map<std::string, std::vector<std::string>> mp;

    for(const auto& s: arr) {
        std::string sCloned{s};
        std::sort(sCloned.begin(), sCloned.end());
        mp[sCloned].push_back(s);
    }

    std::vector<std::vector<std::string>> result;
    for(const auto& pr: mp) {
        result.push_back(pr.second);
    }
    return result;
}