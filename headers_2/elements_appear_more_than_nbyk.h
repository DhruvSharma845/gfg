#pragma once

#include <vector>
#include <unordered_map>

class ElementsThatAppearMoreThanNKTimes {
public:
    std::vector<int> findElements(const std::vector<int>& arr, int K);
};

std::vector<int> ElementsThatAppearMoreThanNKTimes::findElements(const std::vector<int>& arr, int K) {
    std::unordered_map<int, int> freqMap;

    for(int i = 0; i < arr.size(); ++i) {
        if(freqMap.find(arr[i]) != freqMap.end()) {
            freqMap[arr[i]]++;
        }
        else {
            if(freqMap.size() == K - 1) {
                for(auto it = freqMap.begin(); it != freqMap.end();) {
                    freqMap[(*it).first]--;
                    if(freqMap[(*it).second] == 0) {
                        it = freqMap.erase(it);
                    }
                }
            }
            freqMap[arr[i]]++;
        }
    }
    std::vector<int> res;
    for(const auto& pr: freqMap) {
        int count = 0;
        for(int i = 0; i < arr.size(); ++i) {
            if(pr.first == arr[i]) {
                ++count;
            }
        }
        if(count > arr.size() / K) {
            res.push_back(pr.first);
        }
    }
    return res;
}