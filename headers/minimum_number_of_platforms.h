#pragma once

#include <vector>
#include <utility>
#include <algorithm>

class MinimumNumberOfPlatforms {
public:
    int getNumber(const std::vector<std::pair<int,int>>& timelines);
};

int MinimumNumberOfPlatforms::getNumber(const std::vector<std::pair<int,int>>& timelines) {
    std::vector<int> arr;
    std::vector<int> dep;
    std::for_each(timelines.begin(), timelines.end(), [&arr, &dep](const auto& pr) {
        arr.push_back(pr.first);
        dep.push_back(pr.second);
    });

    std::sort(arr.begin(), arr.end());
    std::sort(dep.begin(), dep.end());

    int minimumPlatforms = 0;
    int currentMinPlatforms = 0;
    int first = 0, second = 0;
    while (first < arr.size() && second < dep.size()) {
        if(arr[first] <= dep[second]) {
            ++first;
            ++currentMinPlatforms;
        }
        else if(arr[first] > dep[second]) {
            ++second;
            --currentMinPlatforms;
        }
        if(currentMinPlatforms > minimumPlatforms) {
            minimumPlatforms = currentMinPlatforms;
        }
    }
    return minimumPlatforms;
}