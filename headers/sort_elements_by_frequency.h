#pragma once

#include <vector>
#include <unordered_map>
#include <utility>

class SortArrayByFrequency {
public:
    void doSort(std::vector<int>& arr);
};

void SortArrayByFrequency::doSort(std::vector<int>& arr) {
    std::unordered_map<int, std::pair<int, int>> frequencyMap;
    for(int i = 0; i < arr.size(); ++i) {
        if(frequencyMap.find(arr[i]) == frequencyMap.end()) {
            frequencyMap.insert(std::make_pair(arr[i], std::make_pair(i, 1)));
        }
        else {
            (frequencyMap[arr[i]].second)++;
        }
    }
    using FrequencyArrayPair = std::pair<int, std::pair<int, int>>;
    std::vector<FrequencyArrayPair> frequencyMapArray(frequencyMap.size());

    int i = 0;
    for(const auto& pr: frequencyMap) {
        frequencyMapArray[i] = std::make_pair(pr.first, pr.second);
        ++i;
    }

    std::sort(frequencyMapArray.begin(), frequencyMapArray.end(), [](const FrequencyArrayPair& a, const FrequencyArrayPair& b) {
        if(a.second.second != b.second.second) {
            return a.second.second > b.second.second;
        }
        else {
            return a.second.first < b.second.first;
        }
    });

    i = 0;
    for(const auto& element: frequencyMapArray) {
        for(int j = 0; j < element.second.second; ++j) {
            arr[i] = element.first;
            ++i;
        }
    }
}
